/*
*   main.c
*/

#include "types.h"
#include "memory.h"
#include "crypto.h"
#include "i2c.h"
#include "fs.h"
#include "firm.h"
#include "utils.h"
#include "buttons.h"
#include "../build/bundled.h"

static void (*const itcmStub)(Firm *firm) = (void (*const)(Firm *))0x01FF8000;
static volatile Arm11Operation *operation = (volatile Arm11Operation *)0x1FF80204;

static void invokeArm11Function(Arm11Operation op)
{
    while(*operation != ARM11_READY);
    *operation = op;
    while(*operation != ARM11_READY);
}

static void loadFirm(void)
{
    static const char *firmName = "b00t.firm";

    Firm *firm = (Firm *)0x18000000;
    fileRead(firm, firmName, 0, 0x300000);

    memcpy((void *)itcmStub, itcm_stub_bin, itcm_stub_bin_size);

    //Launch firm
    invokeArm11Function(PREPARE_ARM11_FOR_FIRMLAUNCH);
    itcmStub(firm);
}

void main(void)
{
    if(mountSd())
    {
        loadFirm();
        unmountSd();
    }

    mcuPowerOff();
}

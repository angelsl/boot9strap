#include "types.h"
#include "memory.h"

#define BRIGHTNESS 0x39

void prepareForFirmlaunch(void);
extern u32 prepareForFirmlaunchSize;

extern volatile Arm11Operation operation;

void main(void)
{
    operation = ARM11_READY;

    while(true)
    {
        switch(operation)
        {
            case ARM11_READY:
                continue;
            case PREPARE_ARM11_FOR_FIRMLAUNCH:
                memcpy((void *)0x1FFFFC00, (void *)prepareForFirmlaunch, prepareForFirmlaunchSize);
                *(vu32 *)0x1FFFFFFC = 0;
                ((void (*)(u32, volatile Arm11Operation *))0x1FFFFC00)(ARM11_READY, &operation);
        }

        operation = ARM11_READY;
    }
}

Boot9strap for strange flashcarts
=====

This is boot9strap with the dabort (and thus bootrom dumping) features removed so that it can fit
within 0x4000 bytes.

`boot9strap_ntr.firm` should be flashed so it shows up at 0x7E00 (as per normal).

`boot9strap_ntr.firm.neg` should be flashed so it shows up at 0x4000.

---

![License](https://img.shields.io/badge/License-GPLv3-blue.svg)

Boot9/Boot11 code execution.

For more details, refer to the presentation [here](https://sciresm.github.io/33-and-a-half-c3/).

Install via [SafeB9SInstaller](https://github.com/d0k3/SafeB9SInstaller).

Launches "boot.firm" off of the SD card or CTRNAND. Hold Start + Select + X on boot to dump the bootroms/your OTP.

**Credits:**

[Normmatt](https://github.com/Normmatt): Theorizing the NDMA overwite exploit.    
[TuxSH](https://github.com/TuxSH): Help implementing bootrom payloads.    
[Luma3DS](https://github.com/AuroraWright/Luma3DS): Codebase used in the stage 2 FIRM loader.    

**Licensing:**

This software is licensed under the terms of the GPLv3.  
You can find a copy of the license in the LICENSE file.

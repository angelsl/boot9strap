.arm.little

; FIXME armips is now a glorified padding tool
.create "build/code9.bin",0x08000200
.org 0x08000200
.area 0x10000
.incbin "stage2/arm9/out/arm9.bin"
.align 0x200
.endarea

.close

.create "build/code11.bin",code_11_load_addr
.area 0x10000
.incbin "stage2/arm11/out/arm11.bin"
.align 0x200
.endarea

.close

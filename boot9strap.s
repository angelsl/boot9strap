.arm.little

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Useful constant addresses.

b9_memcpy equ 0xFFFF03F0
b9_store_addr equ 0x08080000
b11_store_addr equ 0x08090000
b11_axi_addr equ 0x1FFC0000

code_11_load_addr equ 0x1FF80000

arm9mem_dabrt_loc equ 0x08000028

.create "build/code9.bin",0x08000200
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; stage 2: Load stage 2 payload to 0x08001000.
.org 0x08000200
.area 0x10000
.incbin "stage2/arm9/out/arm9.bin"
.endarea
.align 0x200

.close
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.create "build/code11.bin",code_11_load_addr
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.area 0x10000
.incbin "stage2/arm11/out/arm11.bin"
.endarea
.align 0x200

.close

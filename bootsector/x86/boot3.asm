[ORG 0x7C00]
[BITS 16]

main:
	call _printstr
	jmp $
	
_printstr:
	mov si,mstart
	mov ah,0x0E
	mov bl,0x07
	mov bh,0x0
	.loop:
	  lodsb
	  or al,al
	  jz .endloop
	  int 0x10
	  jmp .loop
	.endloop:
	 ret

mstart db 'Bem vindo ao seu OS', 13,10,0

times 510-($-$$) db 0

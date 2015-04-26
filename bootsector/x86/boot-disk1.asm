[ORG 0x7C00]
[BITS 16]

main:
	call printstr
	call loadsector
	jmp $
	
printstr:
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

loadsector:
	mov ax,0x500
	mov es,ax
	xor bx,bx
	mov dh,bl
	mov ch,bl
	mov cl,0x02
	mov al,0x01
	mov ah,0x02
	int 0x13
	jz .loaded
	call error
	.loaded:
	jmp 0x500

error:
	mov si, loaderror
	call printstr
	jmp $
	

mstart db 'Bem vindo ao seu OS...', 13,10,0
loaderror db 'Error: Invalid Disk ... ',13,10,0

times 510-($-$$) db 0

dw 0xaa55


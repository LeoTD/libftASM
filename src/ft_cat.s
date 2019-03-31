; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_cat:
; ⎣-------------------------

default		rel
global		_ft_cat

section		.data
buf:	times 1024 db 0		;Define the buffer with a size of 1024 bytes.
bufsize	equ 1024

section		.text
_ft_cat:
	push	r12					; Preserve value of r12.
	push	r13					; Preserve value of r13.
	mov		r12, rdi			; Store fd in r12.

read:
	mov		rax, 0x2000003		; read(
	mov		rdi, r12			;	0,
	mov		rsi, buf			;	buf,
	mov		rdx, bufsize		;	1024)
	syscall
	jc		end					; MacOS/BSD specific. Syscall errors set CF=1.
	cmp		rax, 0
	jbe		end
	mov		r13, rax			; Store return value of read. (read_num)

write:
	mov		rax, 0x2000004		; write(
	mov		rdi, 1				;	1,
	mov		rsi, buf			;	buf,
	mov		rdx, r13			;	read_num)
	syscall
	jc		end
	cmp		rax, 0
	ja		read


end:
	pop		r13
	pop		r12
	xor		rax, rax
	ret

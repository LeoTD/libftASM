; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_puts:
; ⎢  Takes a null terminated string and prints it to stdout
; ⎢  followed by a newline.
; ⎣-------------------------

			default		rel
			global		_ft_puts

			extern		_ft_strlen
			section		.text
_ft_puts:
	mov		r11, rdi
	call	_ft_strlen
	mov		rdx, rax
	mov		rax, 0x2000004		; ⎢  Set rax to determine which system call.
	lea		rsi, [r11]			; ⎢  rsi = *ptr to the string
	mov		rdi, 1				; ⎢  rdi = fd
	syscall
	ret

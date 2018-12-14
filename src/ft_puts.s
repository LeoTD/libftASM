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
	mov		rdx, 6
	mov		rax, 1		; ⎢  Set rax to determine which system call. (1 = write)
	mov		rsi, msg	; ⎢  rsi = *ptr to the string
	mov		rdi, 1		; ⎢  rdi = fd
	syscall
	ret

			section		.data
	msg		db			"Hello\n"

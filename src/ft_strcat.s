			default		rel
			global		_ft_strcat

			section		.text

			;rdi = s1
			;rsi = s2
_ft_strcat:
	mov		rax, rdi	;set return value to address of 1st string
	cmp		rdi, 0		;check for null pointers
	jz		return
	cmp		rsi, 0
	jz		return

skip_loop:				;cycle through 1st string until null terminator
	cmp		byte[rdi], 0
	jz		copy_loop
	inc		rdi
	jmp		skip_loop

copy_loop:
	cmp		byte[rsi], 0
	jz		return
	mov		r8b, byte[rsi]
	mov		byte[rdi], r8b
	inc		rsi
	inc		rdi
	jmp		copy_loop

return:
	mov		byte[rdi], 0
	ret
			default		rel
			global		_ft_bzero

			section		.text
_ft_bzero:
	cmp		rdi, 0
	jz		return
	mov		rcx, rsi

zero_loop:
	mov		byte[rdi], 0
	inc		rdi
	loop	zero_loop

return:
	ret
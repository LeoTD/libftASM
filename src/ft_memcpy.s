; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_memcpy:
; ⎣-------------------------

			default		rel
			global		_ft_memcpy

			section		.text
_ft_memcpy:
	mov		rax, rdi
	cmp		rdi, 0
	je		return
	cmp		rsi, 0
	je		return
	mov		rcx, rdx
	rep		movsb

return:
	ret

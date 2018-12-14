; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_isdigit:
; ⎢  Takes a character and returns [ 1 ] if it is a digit.
; ⎢  Else, returns [ 0 ].
; ⎣-------------------------

			default		rel
			global		_ft_isdigit

			section		.text
_ft_isdigit:
	xor		rax, rax
	sub		rdi, '0'	; ⎢  Align to lower range boundary. This allows an unsigned comparison.
	cmp		rdi, 10		; ⎢  Compare against size of range.
	jae		false		; ⎢  Jump if above or equal. Ignores sign flag.
	inc		rax
false:
	ret

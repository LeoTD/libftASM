; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_islower:
; ⎢  Takes a character and returns [ 1 ] if it is an lowercase letter.
; ⎢  Else, returns [ 0 ].
; ⎣-------------------------

			default		rel
			global		_ft_islower

			section		.text
_ft_islower:
	xor		rax, rax
	sub		rdi, 97		; ⎢  Align to lower range boundary. This allows an unsigned comparison.
	cmp		rdi, 26		; ⎢  Compare against size of range.
	jae		false		; ⎢  Jump if above or equal. Ignores sign flag.
	inc		rax
false:
	ret

; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_isupper:
; ⎢  Takes a character and returns [ 1 ] if it is an uppercase letter.
; ⎢  Else, returns [ 0 ].
; ⎣-------------------------

			default		rel
			global		_ft_isupper

			section		.text
_ft_isupper:
	xor		rax, rax
	sub		rdi, 'A'	; ⎢  Align to lower range boundary. This allows an unsigned comparison.
	cmp		rdi, 26		; ⎢  Compare against size of range.
	jae		false		; ⎢  Jump if above or equal. Ignores sign flag.
	inc		rax
false:
	ret

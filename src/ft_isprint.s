; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_isprint:
; ⎢  Takes a character and returns [ 1 ] if it is an printable character.
; ⎢  Else, returns [ 0 ].
; ⎣-------------------------

			default		rel
			global		_ft_isprint

			section		.text
_ft_isprint:
	xor		rax, rax
	sub		rdi, ' '	; ⎢  Align to lower range boundary. This allows an unsigned comparison.
	cmp		rdi, 95		; ⎢  Compare against size of range.
	jae		false		; ⎢  Jump if above or equal. Ignores sign flag.
	inc		rax
false:
	ret

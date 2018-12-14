; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_tolower:
; ⎢  Converts uppercase to lowercase if the character is a letter.
; ⎢  Else, returns the character unchanged.
; ⎣-------------------------

			default		rel
			global		_ft_tolower

			section		.text
_ft_tolower:
	mov		rax, rdi
	sub		rdi, 'A'			; ⎢  Align to lower range boundary.
	cmp		rdi, 26				; ⎢  Compare against size of range.
	jae		false				; ⎢  Jump if above or equal.
	or		rax, 0b0010_0000	; ⎢  Convert to lowercase.
false:
	ret

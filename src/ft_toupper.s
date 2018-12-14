; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_toupper:
; ⎢  Converts lowercase to uppercase if the character is a letter.
; ⎢  Else, returns the character unchanged.
; ⎣-------------------------

			default		rel
			global		_ft_toupper

			section		.text
_ft_toupper:
	mov		rax, rdi
	sub		rdi, 'a'			; ⎢  Align to lower range boundary.
	cmp		rdi, 26				; ⎢  Compare against size of range.
	jae		false				; ⎢  Jump if above or equal.
	and		rax, 0b1101_1111	; ⎢  Convert to uppercase.
false:
	ret

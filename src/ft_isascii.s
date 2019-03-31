; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_isascii:
; ⎢  Takes a char and returns [ 1 ] if it's within the ascii range.
; ⎢  Else, return [ 0 ].
; ⎣-------------------------

			default		rel
			global		_ft_isascii

			section		.text
_ft_isascii:
	xor     rax, rax
	and		dil, 0b1000_0000	; ⎢  Set ZF if sign bit was not set.
	jnz		false				; ⎢  False if non zero result.
	inc		rax
false:
	ret

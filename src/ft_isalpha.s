; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_isalpha:
; ⎢  Takes a character and returns [ 1 ] if it is a letter.
; ⎢  Else, returns [ 0 ].
; ⎣-------------------------

			default		rel
			global		_ft_isalpha

			section		.text
_ft_isalpha:
	xor		rax, rax
	and		dil, 0b1101_1111	; ⎢  Turn lowercase into upper
	sub		dil, 'A'			; ⎢  Align range boundary to 0
	cmp		dil, 26				; ⎢  compare against range size
	jae		false
	inc		rax
false:
	ret

; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_isalnum:
; ⎢  Takes a character and returns [ 1 ] if it is a digit or a letter.
; ⎢  Else, returns [ 0 ].
; ⎣-------------------------

			default		rel
			global		_ft_isalnum

			extern		_ft_isalpha
			extern		_ft_isdigit
			section		.text
_ft_isalnum:
	call	_ft_isdigit
	add		rdi, '0'
	cmp		rax, 0
	jnz		true
	call	_ft_isalpha
true:
	ret

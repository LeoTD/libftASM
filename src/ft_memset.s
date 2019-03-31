; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_memset:
; ⎢  Takes a pointer to memory, a value, and a length.
; ⎢  Fills [ length ] amount of memory with the given [ value ] beginning
; ⎢  at the given pointer.
; ⎣-------------------------

			default		rel
			global		_ft_memset

			section		.text
_ft_memset:
	mov		r8, rax			; ⎢  Store original pointer for return value
	mov		al, sil			; ⎢  Put the copy value in rax
	mov		rcx, rdx		; ⎢  Put the len count in rcx
	rep		stosb			; ⎢  Do the copying (repeating with rep)
	mov		rax, r8			; ⎢  Restore return value
	ret

; ⎡----------------------------------------------------------------------------⎤
; ⎢  ft_strdup:
; ⎣-------------------------

default		rel
global		_ft_strdup

extern		_malloc
extern		_ft_memcpy
extern		_ft_strlen

section		.text
_ft_strdup:
	push	r12			; Preserve value.
	push	r13
	mov		r12, rdi	; Store str pointer.
	call	_ft_strlen	; Get length in rax.
	inc		rax			; Create space for null.
	mov		r13, rax	; Store len.
	mov		rdi, rax	; Args for malloc.
	call	_malloc
	cmp		rax, 0
	jz		malloc_fail
	mov		rdi, rax
	mov		rsi, r12
	mov		rcx, r13
	mov		r12, rax
	call	_ft_memcpy

end:
	mov		rax, r12
	pop		r13			; Restore.
	pop		r12			; Restore.
	ret

malloc_fail:
	pop		r13			; Restore.
	pop		r12			; Restore.
	xor		rax, rax
	ret

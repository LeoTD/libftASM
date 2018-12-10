			default		rel
			global		_ft_leo
			extern		_malloc
; rdi
; rsi
; rdx
; rcx	

			section		.text
; allocate rdi (1st argument)
_ft_leo:
			xor			rax, rax	; both set it to zero
			mov			rax, 0
			cmp			rdi, 0
			jz			finish
			sub			rsp, 8
;			push		rdi
			call		_malloc ; mov rax, (call _malloc)
;			pop			rdi
			add			rsp, 8

finish:
			ret

		



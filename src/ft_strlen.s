			default		rel
			global		_ft_strlen

			section		.text
_ft_strlen:
			xor			rax, rax			; 0x0
			xor			rcx, rcx			; rdi is "Hello World"
			not			rcx					; 0xFFFFFFFF
			repne		scasb				;
			not			rcx
			mov			rax, rcx
			dec			rax
			ret

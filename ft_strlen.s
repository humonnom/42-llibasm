section	.text
			global		_ft_strlen
											; size_t	ft_strlen(const char *s)
											; rdi = s
_ft_strlen:								
			mov			rax, rdi			; put rax to rdi
			jmp			.cnt				; start with count

			.inc:
				inc		rax					; increase rax


			.cnt:
				cmp		BYTE[rax], 0		; compare rax's byte and eof (compare *rax and 0)
				jne		.inc				; jump if not equal (increase rax)

			.end:
				sub		rax, rdi			; subtraction (rax -= rdi)
											; rdi has the rax's initial value
			ret								; rax has renewed value

; [ ft_strlen ]
; size_t	ft_strlen(const char *s)
; rdi = s

section	.text
			global		_ft_strlen

_ft_strlen:								
			mov			rax, rdi			; put s to rax
			jmp			.cnt				; start with count

			.inc:
				inc		rax					; increase s

			.cnt:
				cmp		BYTE[rax], 0		; compare *(s) and eof
				jne		.inc				; jump if not equal

			sub		rax, rdi				; subtraction (rax -= rdi) 
			ret								; rax has renewed value

	; [rax -= rdi]
	; [s][t][r][i][n][g][\0]
	;  ^              ^
	; rdi            rax
	; (5)            (11)
	; 11 - 5 = 6 ---> len of "string"

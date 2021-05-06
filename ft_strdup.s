section	.text
			extern		_ft_strlen
			extern		_ft_strcpy
			extern		_malloc
			extern		___error
			global		_ft_strdup
													; char	*ft_strdup(const char *s1)
													; rdi = s1;
_ft_strdup:
			push		rdi							; save s1 to stack
			call		_ft_strlen					; len = ft_strlen(rdi) 
			inc			rax							; len++
			mov			rdi, rax					; rdi = len 
			call		_malloc						; address = malloc(rdi) 
			cmp			rax, 0						; compare NULL, address
			je			error						; if address is NULL, go to error
			mov			rdi, rax					; rdi = alloced memory address
			pop			rsi							; bring back s1 to rsi (rsi = s1)
			call		_ft_strcpy					; copy rsi(s1) to rdi(alloced memory = s2)
			ret

error:
			push	rax					; save errno
			call	___error			; rax -> errno variable
			pop		qword[rax]			; qword is data size
			mov		rax, -1
			ret

	; [ General-purpose registers ]
	; R0 - R7: each register has it's own name.
	; R8 - R15: are the new registers and have no other names.

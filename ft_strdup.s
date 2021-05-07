; [ ft_strdup ]
; char	*ft_strdup(const char *s1)
; rdi = s1

section	.text
			global		_ft_strdup
			extern		_ft_strlen					; rdi = s
			extern		_ft_strcpy					; rdi = dst, rsi = src
			extern		_malloc						; rdi = size
			extern		___error

_ft_strdup:
			push		rdi							; store s1 to stack
			call		_ft_strlen					; len = ft_strlen(rdi: s1) 
			inc			rax							; len++
			mov			rdi, rax					; rdi = len 
			call		_malloc						; address = malloc(rdi: len) 
			cmp			rax, 0						; compare NULL, address
			je			err							; if address is NULL, go to err
			mov			rdi, rax					; rdi = alloced memory address
			pop			rsi							; bring back s1 to rsi (rsi = s1)
			call		_ft_strcpy					; copy rsi(s1) to rdi(alloced memory = s2)
			ret

err:
			push	rax					; save err
			call	___error			; rax -> errno variable
			pop		qword[rax]			; qword is data size
			mov		rax, 0
			ret

	; [ General-purpose registers ]
	; R0 - R7: each register has it's own name.
	; R8 - R15: are the new registers and have no other names.

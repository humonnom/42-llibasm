; [ ft_strcmp ]
; int	ft_strcmp(const char *s1, const char *s2)
; rdi = s1, rsi = s2

section	.text
			global		_ft_strcmp

_ft_strcmp:
			mov		rax, 0							; init register
			mov		rcx, 0
			mov		rdx, 0
			jmp		.cmp_loop						; start with loop
		
			.inc_idx:
				inc		rdx							; increase index
		
			.cmp_loop:								; compare each byte
				mov		al, BYTE[rdi + rdx]			; al = *(s1 + index)
				cmp		al, 0						; compare with eof
				je		.set_ret					; jump if equal --> set return value
				cmp		al, BYTE[rsi + rdx]			; compare with *(s2 + index)
				je		.inc_idx					; jump if equal
		
			.set_ret:
				mov		cl, BYTE[rsi + rdx]			; cl = *(s2 + index)
				sub		rax, rcx					; ret = *(s1 + index) - *(s2 + index)

			ret
	
	; [ mismatch in operand size ]
	; sub rax, cl --> error

	; [ 8 bits register ]
	; al is rax's first 8 bits (size of char)
	; a menas 'accumulator'
	; r means 'register'
	; [                   rax                     ] --> 64bits
	;                         [        eax        ] --> 32bits(extended ax)
	;                                  [    ax    ]	--> 16bits(pair)
	;                                  [ ah ]       --> 8bits(high)
    ;                                        [ al ] --> 8bits(low)
	; cl is rcx's first 8 bits (size of char)

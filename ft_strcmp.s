section	.text
			global		_ft_strcmp
											; int	ft_strcmp(const char *s1, const char *s2)
											; rdi = s1, rsi = s2
_ft_strcmp:
	mov		rax, 0							; init register
	mov		rcx, 0							;
	mov		rdx, 0							;
	jmp		.cmp_loop							; start with loop

	.inc_idx:
		inc		rdx							; increase index(rdx)

	.cmp_loop:
		mov		al, BYTE[rdi + rdx]			; al = *(s1 + index)
		cmp		al, 0						; if al is eof
		je		.set_ret					; jump to end
		cmp		al, BYTE[rsi + rdx]			; if al equal *(s2 + index)
		je		.inc_idx					; jump to inc 

	.set_ret:
		mov		cl, BYTE[rsi + rdx]			; cl = *(s2 + index)
		sub		rax, rcx					; ret = *(s1 + index) - *(s2 + index)

	ret

	; [8 bits register]
	; al is rax's first 8 bits (size of char)
	; cl is rcx's first 8 bits (size of char)

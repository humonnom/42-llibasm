section	.text
			global		_ft_strcpy
													; char	*ft_strcpy(char *dst, const char *src)
													; rdi = dst, rsi = src
_ft_strcpy:
			mov			rax, 0							; init register
			jmp			.copy_loop						; start with loop

			.inc_idx:
				inc		rax							; increase index(rax)

			.copy_loop:
				mov		dl, BYTE[rsi + rax]			; dl is tmp register (size of char), dl: *(dst + index)
				mov		BYTE[rdi + rax], dl			; copy
				cmp		dl, 0						; check eof
				jne		.inc_idx					; if it's not done, go to inc_idx 

			mov			rax, rdi

			ret

			; [register]
			; rax is accumulator (eax, ax, ah, al)
			; rbx is base register (ebx, bx, bh, bl)
			; rcx is counter register (ecx, cx, ch, cl)
			; rdx is data register (edx, dx, dh, dl)

section	.text
			global	_ft_write
			extern ___error
			WRITE_FUNC equ 0x2000004


_ft_write:								; rdi = fd , rsi = str(buf), rdx = str_length
			mov		rax, WRITE_FUNC		; write()
			syscall						; execute
			jc		err					; check error
			ret							; return

err:
			push	rax					; save errno
			call	___error			; rax -> errno variable
			pop		qword[rax]			; qword is data size
			mov		rax, -1
			ret

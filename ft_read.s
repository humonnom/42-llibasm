section	.text
			global	_ft_read
			extern ___error
			READ_FUNC equ 0x2000003

_ft_read:								; rdi = fd , rsi = str(buf), rdx = str_length
			mov		rax, READ_FUNC		; write()
			syscall						; execute
			jc		err					; check error
			ret							; return

err:
			push	rax					; save errno
			call	___error			; rax -> errno variable
			pop		qword[rcx]			; qword is data size
			mov		[rax], rcx
			mov		rax, -1
			ret

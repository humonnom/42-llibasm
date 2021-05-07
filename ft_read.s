; [ ft_read ]
; ssize_t	ft_read(int fd, void *buf, size_t count)
; rdi = fd , rsi = buf, rdx = count 

section	.text
			global			_ft_read
			extern 			___error
			READ_FUNC equ 	0x2000003

_ft_read:
			mov			rax, READ_FUNC		; read()
			syscall							; execute
			jc			err					; check error
			ret								; return

err:
			push		rax					; save errno
			call		___error			; rax -> errno variable
			pop			qword[rax]			; qword is data size
			mov			rax, -1
			ret

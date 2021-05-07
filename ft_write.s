; [ ft_write ]
; ssize_t	ft_write(int fd, const void *buf, size_t count)
; rdi = fd , rsi = buf, rdx = count 

section	.text
			global			_ft_write
			extern 			___error		; use to set errno(get errno address) 
			WRITE_FUNC equ	0x2000004		; class(2000000) & unix system call number(4)

_ft_write:
			mov			rax, WRITE_FUNC		; write()
			syscall							; execute -> if error occured, set carry flag on
			jc			err					; check error (carry flag)
			ret								; return

err:
			push		rax					; rax has errno -> save errno in stack
			call		___error			; rax has errno variable's address
			pop			qword[rax]			; get errno from stack -> *(rax)
			mov			rax, -1				; set return value
			ret

	; [opcode, operand]
	; opcode: commend
	; operand: factor
	; form-> opcode operand(dst), operand(src)

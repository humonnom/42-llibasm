section	.data
	msg db "hello world",0x0A	; msg = variable name | db = data type(byte) | 0x0A = new line character
								; db = data byte(1 byte) | dw = data word(4 byte) | dd = date double(8 byte) 
section .text
	global _hello					; globally accessible

_hello :
	mov rax, 0x2000004			; 0x2000004 is MAC OS's syscall write() function num.
	mov rdi, 1					; following lines are parameters.
	mov rsi, msg
	mov rdx, 12
	syscall						; call
	mov rax, 0x2000001			; 0x2000001 is MAC OS's syscall exit() function num.
	mov rdi, 0					; following line is parameter.
	syscall						; call

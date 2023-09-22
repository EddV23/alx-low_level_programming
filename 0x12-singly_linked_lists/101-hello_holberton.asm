section .data
	message: db "Hello, Holberton", 0
	format:	 db "%s", 10, 0

section .text
	global main

extern printf

main:
	push rbp
	mov rdi, format
	mov rsi, message
	call printf
	pop rbp
	mov rax, 0x60
	xor rdi, rdi
	ret

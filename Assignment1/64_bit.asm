global _start

section .data
	message db "helloworld", 10, 0

section .text

_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, message
	mov rdx, 13
	syscall
	mov rax, 60
	mov rdi, 0
	syscall

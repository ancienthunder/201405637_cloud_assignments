extern printf
global main

section .data
	message db "helloworld", 10, 0

section .text

main:
	pushad
	push dword message
	call printf
	add esp, 4
	popad
	ret

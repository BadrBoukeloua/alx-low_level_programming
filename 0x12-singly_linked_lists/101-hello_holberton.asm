global main
extern printf


section .data
    hello: db "Hello, Holberton!", 10, 0

section .text
main:
    mov rdi, hello
    xor eax, eax
    call printf
    xor eax, eax
    ret

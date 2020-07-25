
section .text
global __start
__start:
  mov rax, 0x2000004 ; write
  mov rdi, 1 ; stdout
  mov rsi, msg
  mov rdx, msg.len
  syscall
  ret
section .data
msg:    db      "Hello, world!", 10
.len:   equ     $ - msg
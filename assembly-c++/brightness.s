section .text
global __start

; RDI	1st argument
; RSI	2nd argument
; RDX	3rd argument
; RCX	4th argument

;    uchar* new_image, RDI
;     uchar* old_image, RSI
;     short  brit,
;     Size_<int>  size

default rel
__start:
    mov r10, 0
    cmp rdx, 0
    jl  ReduceBright

    mov r11w, 0ffffh

mainLoop:
    movsx eax, word [rsi]
    add eax, edx
    cmovc ax, r11w
    mov [rdi], eax
   
    inc rsi 
    inc rdi
    dec rcx
    jnz mainLoop
    
    ret
    
ReduceBright: 
    mov r11w, 0
    neg r8w

MainLoopSubtract:
    mov al, byte [rdx + r10]
    sub al, r8b
    cmovc ax, r11w
    mov  byte [rcx + r10], al
    inc r10
    dec r9d
    jnz MainLoopSubtract
    ret
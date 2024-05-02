%include "io64.inc"

section .text
bits 64
default rel
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    PRINT_STRING "LEMME ADD TWO NUMBERS LEZGAUR"
    NEWLINE
    mov rcx, 5
    PRINT_UDEC 2, rcx
    mov rdx, 10
    PRINT_STRING " + "
    PRINT_UDEC 2, rdx
    add rcx, rdx
    mov rax, rcx
    PRINT_STRING " = "
    PRINT_UDEC 2, rax
    ;mov rdx, 10
    ;add rcx, rdx
    ;mov rax, rcx
    ;PRINT_STRING eax
    ret
    
    
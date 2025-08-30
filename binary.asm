section .bss
    binary_num resd 32
    binary_copy resd 32

section .text
    global ToBinary

ToBinary:
    ; Input: rdi = num (unsigned int)
    ; Output: rax = result (int)

    xor rax, rax          ; Clear rax for the result
    xor rcx, rcx          ; Clear rcx for index i

.loop1:
    test rdi, rdi         ; Check if num > 0
    jz .end_loop1         ; If num is 0, exit loop

    mov rdx, rdi          ; Copy num to rdx
    and rdx, 1            ; Get the last bit (num % 2)
    mov [binary_num + rcx*4], edx ; Store in binary_num[i]
    
    shr rdi, 1            ; num = num / 2
    inc rcx               ; i++
    jmp .loop1            ; Repeat the loop

.end_loop1:
    dec rcx               ; Adjust i for the next loop

.loop2:
    cmp rcx, 0            ; Check if j >= 0
    jl .end_loop2         ; If j < 0, exit loop

    mov edx, [binary_num + rcx*4] ; Load binary_num[j]
    imul rax, rax, 10
    add rax, [binary_num + rcx*4]
    
    dec rcx               ; j--
    jmp .loop2            ; Repeat the loop

.end_loop2:
    ret

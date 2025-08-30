section .bss
    binary_num resd 32
    binary_copy resd 32

section .text
    global ToBinary

ToBinary:
    xor rax, rax          
    xor rcx, rcx         

.loop1:
    test rdi, rdi         
    jz .end_loop1         

    mov rdx, rdi          
    and rdx, 1            
    mov [binary_num + rcx*4], edx 
    
    shr rdi, 1   
    inc rcx
    jmp .loop1     

.end_loop1:
    dec rcx         

.loop2:
    cmp rcx, 0    
    jl .end_loop2  

    mov edx, [binary_num + rcx*4]
    imul rax, rax, 10
    add rax, [binary_num + rcx*4]
    
    dec rcx     
    jmp .loop2      

.end_loop2:
    ret

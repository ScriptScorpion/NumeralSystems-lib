section .bss
    hex_num resb 32
    res resb 32

section .text
    global ToHex

ToHex:
    ; Input: rdi = num
    ; Output: rax = pointer to res
    cmp rdi, 0
    jl exit
    xor rbx, rbx        
    mov rcx, rdi ; making copy of input
    mov rsi, 16 ; what will be divided
    jmp .loop

.loop:
    xor rdx, rdx
    cmp rcx, 0
    jle .convert         
    mov rax, rcx
    div rsi ; division is (rax : rsi) remainder is in rdx and result of division is in rax
    mov [hex_num + rbx], dl 
    inc rbx              
    mov rcx, rax    
    jmp .loop

.convert:
    dec rbx              
    xor rdi, rdi      
    jmp .reverse

.reverse:
    cmp rbx, 0
    jl .done            

    mov al, [hex_num + rbx] 
    ; if character is < 10 or > 15, store it
    cmp al, 10
    jl .digit             
    cmp al, 15
    ja .digit
    ; else add letter
    add al, 'A' - 10
    jmp .store

.digit:
    add al, '0'
    jmp .store

.store:
    mov [res + rdi], al  
    inc rdi              
    dec rbx               
    jmp .reverse

.done:
    mov BYTE [res + rdi], 0 ; null-terminate the string
    mov rax, res             ; return pointer to res
    xor rsi, rsi

    ret

exit:
    ret

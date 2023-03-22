section .data
    ; Declare data section here

section .text
    global search

    ; Search function
    search:
        ; Declare variables and registers
        push ebp
        mov ebp, esp
        sub esp, 8 ; Allocate space for variables

        ; Load search parameters
        mov eax, [ebp + 8] ; Load search target
        mov ebx, [ebp + 12] ; Load search range start
        mov ecx, [ebp + 16] ; Load search range end

        ; Divide search range among threads
        mov edx, ecx ; Calculate number of threads
        sub edx, ebx
        xor ebx, ebx
        div dword [ebp + 20] ; Divide by thread count
        mov edi, eax ; Save range size per thread
        mov esi, ebx ; Save remainder

        ; Start threads
        mov eax, 0 ; Set initial thread ID
        mov ecx, [ebp + 20] ; Load thread count
        mov edx, esp ; Set up stack pointer for new threads
    loop:
        ; Spawn new thread
        push eax ; Pass thread ID as parameter
        push edx ; Pass stack pointer as parameter
        mov ebx, [ebp + 24] ; Load thread function address
        call ebx ; Call thread function
        add esp, 8 ; Clean up stack

        ; Update search range for next thread
        add [ebp + 12], edi ; Increment search range start
        add [ebp + 16], edi ; Increment search range end
        add [ebp + 20], esi ; Add remainder to next thread

        ; Check for end of loop
        inc eax ; Increment thread ID
        cmp eax, ecx ; Compare to thread count
        jne loop ; Loop again if not at end of range

        ; Clean up stack and return
        add esp, 8 ; Deallocate variable space
        pop ebp
        ret
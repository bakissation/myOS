global start  ; Entry point for the bootloader
extern long_mode_start  ; External symbol for long mode start

section .text
bits 32  ; Set the assembly to 32-bit mode
start:
    ; Initialize the stack pointer
    mov esp, stack_top

    ; Call various initialization functions
    call check_multiboot
    call check_cpuid
    call check_long_mode

    call setup_page_tables
    call enable_paging

    ; Load the Global Descriptor Table (GDT)
    lgdt [gdt64.pointer]

    ; Jump to the long mode entry point
    jmp gdt64.code_segment:long_mode_start

    ; Halt the processor
    hlt

check_multiboot:
    ; Check if the Multiboot header is present
    cmp eax, 0x36d76289
    jne .no_multiboot
    ret
.no_multiboot:
    ; Print 'M' for Multiboot error
    mov al, "M"
    jmp error

check_cpuid:
    ; Check if CPUID is supported
    pushfd
    pop eax
    mov ecx, eax
    xor eax, 1 << 21
    push eax
    popfd
    pushfd
    pop eax
    push ecx
    popfd
    cmp eax, ecx
    je .no_cpuid
    ret
.no_cpuid:
    ; Print 'C' for CPUID error
    mov al, "C"
    jmp error

check_long_mode:
    ; Check if the CPU supports Long Mode
    mov eax, 0x80000000
    cpuid
    cmp eax, 0x80000001
    jb .no_long_mode

    mov eax, 0x80000001
    cpuid
    test edx, 1 << 29
    jz .no_long_mode

    ret
.no_long_mode:
    ; Print 'L' for Long Mode error
    mov al, "L"
    jmp error

setup_page_tables:
    ; Set up page tables for enabling paging
    mov eax, page_table_l3
    or eax, 0b11  ; Present, writable
    mov [page_table_l4], eax

    mov eax, page_table_l2
    or eax, 0b11  ; Present, writable
    mov [page_table_l3], eax

    mov ecx, 0  ; Counter
.loop:
    mov eax, 0x200000  ; 2MiB
    mul ecx
    or eax, 0b10000011  ; Present, writable, huge page
    mov [page_table_l2 + ecx * 8], eax

    inc ecx  ; Increment counter
    cmp ecx, 512  ; Check if the whole table is mapped
    jne .loop  ; If not, continue

    ret

enable_paging:
    ; Enable paging and long mode
    ; Pass page table location to the CPU
    mov eax, page_table_l4
    mov cr3, eax

    ; Enable PAE (Physical Address Extension)
    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    ; Enable long mode
    mov ecx, 0xC0000080
    rdmsr
    or eax, 1 << 8
    wrmsr

    ; Enable paging
    mov eax, cr0
    or eax, 1 << 31
    mov cr0, eax

    ret

error:
    ; Display an error message: "ERR: X" where X is the error code
    mov dword [0xb8000], 0x4f524f45
    mov dword [0xb8004], 0x4f3a4f52
    mov dword [0xb8008], 0x4f204f20
    mov byte [0xb800a], al
    hlt

section .bss
align 4096
page_table_l4:
    resb 4096
page_table_l3:
    resb 4096
page_table_l2:
    resb 4096
stack_bottom:
    resb 4096 * 4
stack_top:

section .rodata
gdt64:
    dq 0  ; Zero entry
.code_segment: equ $ - gdt64
    dq (1 << 43) | (1 << 44) | (1 << 47) | (1 << 53)  ; Code segment
.pointer:
    dw $ - gdt64 - 1  ; Length
    dq gdt64  ; Address
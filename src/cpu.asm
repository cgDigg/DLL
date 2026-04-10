; cpuid.asm
.code

GetCpuVendor PROC EXPORT
    ; RCX = char* buffer (caller provides >=13 bytes)
    push rbx

    mov rax, rcx        ; save buffer pointer
    mov ecx, 0          ; CPUID leaf 0
    cpuid               ; EBX, EDX, ECX = vendor string

    mov [rax],     ebx
    mov [rax+4],   edx
    mov [rax+8],   ecx
    mov byte ptr [rax+12], 0  ; null-terminate

    pop rbx
    ret
GetCpuVendor ENDP

END
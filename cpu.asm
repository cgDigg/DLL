; cpuid.asm — keep at repo root so MSVC MASM does not emit Release\src\*.obj (missing subdir)
.code

GetCpuVendor PROC EXPORT
    ; RCX = char* buffer (caller provides >=13 bytes)
    ; Return: void in C — data is written into *buf, not in RAX.
    ; CPUID leaf 0: EAX=max leaf; vendor string = 12 ASCII bytes in EBX, EDX, ECX order (then '\0').
    push rbx

    mov rbx, rcx        ; keep buffer pointer in RBX (CPUID clobbers RAX/EAX)
    xor eax, eax        ; CPUID input leaf = 0
    cpuid

    mov [rbx],     ebx
    mov [rbx+4],   edx
    mov [rbx+8],   ecx
    mov byte ptr [rbx+12], 0

    pop rbx
    ret
GetCpuVendor ENDP

END

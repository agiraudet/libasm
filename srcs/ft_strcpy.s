section	.text
	global	ft_strcpy

ft_strcpy:
	xor		rcx, rcx
	jmp		cpy

cpy:
	mov		rdx, [rsi + rcx]
	mov		[rdi + rcx], rdx
	cmp		byte rdx, 0
	je		exit
	inc		rcx
	jmp		cpy

exit:
	mov		rax, rdi
	ret

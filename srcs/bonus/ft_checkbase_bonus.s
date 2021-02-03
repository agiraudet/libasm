section .text
	global	ft_checkbase
	extern	ft_isspace
	extern	ft_getindex

ft_checkbase:
	xor		eax, eax
	mov		rcx, rdi
	mov		rsi, rdi

.loop:
	movzx	rdi, byte[rcx]
	cmp		dil, 0
	je		.good_base
	call	ft_isspace
	cmp		rax, 1
	je		.bad_base
	cmp		dil, 45
	je		.bad_base
	cmp		dil, 43
	je		.bad_base
	push	rcx
	call	ft_getindex
	pop		rcx
	cmp		rax, -1
	je		.bad_base
	inc		rcx
	jmp		.loop

.bad_base:
	xor		eax, eax
	ret

.good_base:
	mov		rax, 1
	ret

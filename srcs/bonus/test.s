section	.text
	global	ft_test

ft_test:
	xor		eax, eax
	mov		r9,	rdi
	mov		r8, rsi
	mov		rdi, [rdi]

.loop:
	test	rdi, rdi
	je		.exit
	mov		rsi, rdi
	mov		rdi, [rdi + 8]
	call	.cmpr
	cmp		rax, 0
	jg		.swap
	jmp		.loop

.swap:
	mov		rcx, [rdi]
	mov		rdi, [rdi + 8]
	mov		rdi, [rdi]
	mov		
	mov		rdi, [r9]
	jmp		.loop

.cmpr:
	xor		eax, eax
	push	rdi
	push	rsi
	mov		rsi, [rdi + 8]
	mov		rsi, [rsi]
	mov		rdi, [rdi]
	call	r8
	pop		rsi
	pop		rdi
	ret

.exit:
	ret

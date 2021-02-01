section	.text
	global	ft_list_sort
	extern	print_lst

ft_list_sort:
	mov		r12, rdi
	mov		r14, rdi
	mov		r13, rsi
	mov		rdi, [rdi]

.loop:
	call	.debug
	mov		rsi, [rdi + 8]
	test	rsi, rsi
	je		.exit
	call	.cmpr
	cmp		rax, 0
	jg		.swap
	mov		r12, rdi
	mov		rdi, rsi

.cmpr:
	push	rsi
	push	rdi
	mov		rsi, [rsi]
	mov		rdi, [rdi]
	xor		eax, eax
	call	r13
	pop		rdi
	pop		rsi
	ret

.swap:
	xor		ecx, ecx
	xor		edx, edx
	push	rsi
	push	rdi
	mov		rdi, [r12]

	mov		rsi, [rdi + 8]
	mov		rdx, [rsi + 8]
	mov		rcx, [rdx + 8]
	mov		[rdi + 8], rdx
	mov		[rsi + 8], rcx
	mov		[rdx + 8], rsi

	pop		rdi
	pop		rsi
	mov		rdi, [r14]
	mov		r12, r14
	jmp		.loop

.exit:
	ret

.debug:
	push	rdi
	mov		rdi, [r14]
	call	print_lst
	pop		rdi
	ret

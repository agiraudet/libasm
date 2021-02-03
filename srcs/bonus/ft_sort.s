section	.text
	global	ft_sort

ft_sort:
	mov		r8, rsi
	mov		r9,	rdi
	mov		rdi, [rdi]

.loop:
	test	rdi, rdi
	je		.exit
	mov		rsi, [rdi + 8]
	test	rsi, rsi
	je		.exit
	call	.cmpr
	cmp		rax, 0
	jg		.call_sw
	
	mov		r9, rdi
	mov		rdi, rsi
	jmp		.loop

.call_sw:
	call	.swap

.cmpr:
	xor		eax, eax
	push	rdi
	push	rsi
	mov		rdi, [rdi]
	test	rsi, rsi
	je		.exit
	mov		rsi, [rsi]
	call	r8
	pop		rsi
	pop		rdi
	ret

.swap:
	mov		rcx, [rsi + 8]
	mov		[r9 + 8], rsi
	mov		[rsi + 8], rdi
	mov		[rdi + 8], rcx
	mov		rdi, [r9]
	jmp		.loop

.exit:
	ret

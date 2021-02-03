section	.text
	global	ft_base
	extern	ft_strlen

ft_base:
	xor		eax, eax
	mov		rdx, rdi
	mov		rdi, rsi
	call	ft_strlen
	mov		rbx, rax

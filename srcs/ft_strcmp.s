section	.text
	global ft_strcmp

ft_strcmp:
	cmp byte [rsi], 0
	je	exit
	mov	al, byte [rsi]
	cmp	byte [rdi], al
	jne exit
	inc rsi
	inc rdi
	jmp	ft_strcmp

exit:
	movzx	eax, byte [rdi]
	movzx	ecx, byte [rsi]
	sub		eax, ecx
	ret

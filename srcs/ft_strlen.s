section .text
	global ft_strlen

ft_strlen:
	xor	rax,rax
	jmp	count

count:
	cmp	byte [rdi + rax], 0
	je	exit
	inc	rax
	jmp	count

exit:
	ret

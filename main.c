/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:26:20 by agiraude          #+#    #+#             */
/*   Updated: 2021/01/25 18:08:47 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libtest.h"

int	main()
{
	printf("ft_strlen: %zu\n", ft_strlen("Hello World!"));
	printf("vs strlen: %zu\n", strlen("Hello World!"));
	printf("\n");

	printf("\n");
	printf("ft_strcmp: %d\n", ft_strcmp("Hello", "Hello"));
	printf("vs strcmp: %d\n", strcmp("Hello", "Hello"));
	printf("\n");
	printf("ft_strcmp: %d\n", ft_strcmp("Helo", "Hello"));
	printf("vs strcmp: %d\n", strcmp("Helo", "Hello"));
	printf("\n");
	printf("ft_strcmp: %d\n", ft_strcmp("Helloo", "Hello"));
	printf("vs strcmp: %d\n", strcmp("Helloo", "Hello"));
	printf("\n");
	printf("ft_strcmp: %d\n", ft_strcmp("Hello", "Hellooooo"));
	printf("vs strcmp: %d\n", strcmp("Hello", "Hellooooo"));
	printf("\n");
	printf("ft_strcmp: %d\n", ft_strcmp("Hello  5", "Hello  4"));
	printf("vs strcmp: %d\n", strcmp("Hello  5", "Hello  4"));
	printf("\n");
	printf("ft_strcmp: %d\n", ft_strcmp("abc", "abd"));
	printf("vs strcmp: %d\n", strcmp("abc", "abd"));
	printf("\n");

	char	*w = "wrote\n";
	write(1, w, strlen(w));
	ft_write(1, w, ft_strlen(w));
	printf("\n");

	char	dest1[100];
	char	dest2[100];
	/*
	printf("ft_strcpy: %s\n", ft_strcpy(dest1, "hi w"));
	printf("strcpy: %s\n", strcpy(dest2, "hi w"));
	*/
	ft_strcpy(dest1, "hello there");
	strcpy(dest2, "hello there");
	printf("ft_strcpy: %s\n", dest1);
	printf("strcpy: %s\n", dest2);

	return (0);
}

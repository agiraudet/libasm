/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:26:20 by agiraude          #+#    #+#             */
/*   Updated: 2021/01/26 13:17:20 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
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

	char	dest1[100];
	char	dest2[100];
	ft_strcpy(dest1, "hello there");
	strcpy(dest2, "hello there");
	printf("ft_strcpy: %s\n", dest1);
	printf("strcpy: %s\n", dest2);
	printf("\n");


	char	*w = "wrote\n";
	printf("wr: %zd\n", write(5, w, strlen(w)));
	perror("write_error: ");
	printf("(errno = %d)\n", errno);
	errno = 0;
	printf("ft: %zd\n", ft_write(5, w, ft_strlen(w)));
	perror("ft_write_error: ");
	printf("(errno = %d)\n\n", errno);

	errno = 0;
	printf("wr: %zd\n", write(1, w, strlen(w)));
	perror("write_error: ");
	printf("(errno = %d)\n", errno);
	errno = 0;
	printf("ft: %zd\n", ft_write(1, w, ft_strlen(w)));
	perror("ft_write_error: ");
	printf("(errno = %d)\n\n", errno);

	printf("\n");
	char	buf1[100] = {0};
	char	buf2[100] = {0};
	printf("read: (%zd) %s", read(0, buf1, 100), buf1);
	printf("ft_read: (%zd) %s", ft_read(0, buf2, 100), buf2);

	printf("\n");
	errno = 0;
	printf("read: (%zd) %s", read(5, buf1, 100), buf1);
	perror("read_error: ");
	printf("(errno = %d)\n", errno);
	errno = 0;
	printf("ft_read: (%zd) %s", ft_read(5, buf2, 100), buf2);
	perror("read_error: ");
	printf("(errno = %d)\n\n", errno);


	char	*dup1;
	char	*dup2;
	char	*src = "tractor rally";
	dup1 = strdup(src);
	dup2 = ft_strdup(src);
	printf("strdup: %s\n", dup1);
	printf("ft_strdup: %s\n", dup2);
	printf("%p\n%p\n", dup2, src);
	free(dup1);
	free(dup2);
	return (0);
}

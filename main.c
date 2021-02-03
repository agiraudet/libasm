/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:26:20 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/03 12:14:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "libasm.h"

int		g_result = 0;
int		g_nb_test = 0;

int	test_strlen(char *str)
{
	int		res1;
	int		res2;

	printf("for \"%s\"\n", str);
	res1 = ft_strlen(str);
	res2 = strlen(str);
	printf("ft_strlen: %d\n", res1);
	printf("vs strlen: %d\n", res2);
	return (res1 == res2);
}

int	test_strcpy(char *str)
{
	char	cpy1[100];
	char	cpy2[100];
	int		res;

	printf("for \"%s\"\n", str);
	ft_strcpy(cpy1, str);
	strcpy(cpy2, str);
	printf("ft_strcpy: |%s|\n", cpy1);
	printf("vs strcpy: |%s|\n", cpy2);
	res = strcmp(cpy1, cpy2) == 0 ? 1 : 0;
	return (res);
}

int	test_strcmp(char *s1, char *s2)
{
	int		res1;
	int		res2;

	printf("for \"%s\" vs \"%s\"\n", s1, s2);
	res1 = ft_strcmp(s1, s2);
	res2 = strcmp(s1, s2);
	printf("ft_strcmp: |%d|\n", res1);
	printf("vs strcmp: |%d|\n", res2);
	return (res1 == res2);
}

int	test_strdup(char *str)
{
	char	*dup1;
	char	*dup2;
	int		res;


	printf("for \"%s\"\n", str);
	dup1 = ft_strdup(str);
	dup2 = strdup(str);
	printf("ft_strdup: |%s|\n", dup1);
	printf("vs strdup: |%s|\n", dup2);
	res = strcmp(dup1, dup2) == 0 ? 1 : 0;
	return (res);
}

int	test_write(char *str, int fd)
{
	ssize_t		res1;
	ssize_t		res2;
	int			err1;
	int			err2;

	printf("for \"%s\" in fd %d\n", str, fd);
	errno = 0;
	res1 = ft_write(fd, str, strlen(str));
	printf("\nft_write: %zd\n", res1);
	err1 = errno;
	if (res1 < 0)
	{
		perror("ft_error: ");
		printf("ft_error nb: %d\n", err1);
	}
	errno = 0;
	res2 = write(fd, str, strlen(str));
	printf("\nvs write: %zd\n", res2);
	err2 = errno;
	if (res2 < 0)
	{
		perror("error: ");
		printf("error nb: %d\n", err1);
	}
	if ((res1 != res2) || (err1 != err2))
		return (0);
	return (1);
}

int	test_read(int fd)
{
	char		buf1[100];
	char		buf2[100];
	int			buf_len = 100;
	ssize_t		res1;
	ssize_t		res2;
	int			err1;
	int			err2;

	bzero(buf1, buf_len);
	bzero(buf2, buf_len);
	printf("for fd %d\n", fd);
	errno = 0;
	res1 = ft_read(fd, buf1, buf_len);
	printf("ft_read: |%s|\n", buf1);
	err1 = errno;
	if (res1 < 0)
	{
		perror("ft_error: ");
		printf("ft_error nb: %d\n", err1);
	}
	errno = 0;
	res2 = read(fd, buf2, buf_len);
	printf("vs read: |%s|\n", buf2);
	err2 = errno;
	if (res2 < 0)
	{
		perror("error: ");
		printf("error nb: %d\n", err1);
	}
	if ((res1 != res2) || (err1 != err2))
		return (0);
	return (1);
}

int	rst(int	res)
{
	if (res == 0)
		printf("\033[0;31mKO\n");
	else
		printf("\033[0;32mOK\n");
	g_nb_test++;
	g_result += res;
	printf("\033[0m\n");
	return (res);
}

int	main(void)
{
	printf("### STRLEN ###\n");
	rst(test_strlen("A"));
	rst(test_strlen("AB"));
	rst(test_strlen("Hello"));
	rst(test_strlen("Hello world!"));
	rst(test_strlen(""));
	printf("##############\n\n");

	printf("### STRCPY ###\n");
	rst(test_strcpy("A"));
	rst(test_strcpy("AB"));
	rst(test_strcpy("Hello"));
	rst(test_strcpy("Hello world!"));
	rst(test_strcpy(""));
	printf("##############\n\n");

	printf("### STRCMP ###\n");
	rst(test_strcmp("A", "A"));
	rst(test_strcmp("AB", "AB"));
	rst(test_strcmp("A", ""));
	rst(test_strcmp("", "A"));
	rst(test_strcmp("Hello", "Hell0"));
	rst(test_strcmp("Hello", "Helo"));
	rst(test_strcmp("Hello", "Helloo"));
	rst(test_strcmp("Hello", "Hel"));
	rst(test_strcmp("Hel", "Hell0"));
	printf("##############\n\n");

	printf("### STRDUP ###\n");
	rst(test_strdup("A"));
	rst(test_strdup("AB"));
	rst(test_strdup("Hello"));
	rst(test_strdup("Hello world!"));
	rst(test_strdup(""));
	printf("##############\n\n");

	printf("###  WRITE ###\n");
	rst(test_write("Hello world!", 1));
	rst(test_write("Hello world!", 99));
	printf("##############\n\n");

	printf("###  READ  ###\n");
	rst(test_read(1));
	rst(test_read(99));
	printf("##############\n\n");

	printf("TOTAL : %d/%d\n", g_result, g_nb_test);
	return (0);
}

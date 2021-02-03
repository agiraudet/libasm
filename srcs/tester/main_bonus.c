/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:16:36 by user42            #+#    #+#             */
/*   Updated: 2021/02/03 17:48:02 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libasm.h"
#include "libasm_bonus.h"

int	get_index(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	pwr(int base, int exp)
{
	int res;

	res = 1;
	while (exp > 1)
	{
		res *= base;
		exp--;
	}
	return (res);
}

int	ft_check_error(char *base)
{
	int sane;
	int basesize;
	int i;
	int index;

	sane = 1;
	i = 0;
	basesize = 0;
	while (base[basesize] && basesize < 2)
		basesize++;
	if (basesize <= 1)
		sane = 0;
	while (base[i])
	{
		if (((base[i] > 8 && base[i] < 14) || base[i] == ' '))
			sane = 0;
		if (base[i] == '+' || base[i] == '-')
			sane = 0;
		index = get_index(base, base[i]);
		if (index != i)
			sane = 0;
		i++;
	}
	return (sane);
}

int	ft_convert_base(char *str, char *base, int i, int end)
{
	int basesize;
	int res;
	int strlen;

	res = 0;
	basesize = 0;
	strlen = 0;
	while (base[basesize])
		basesize++;
	while (str[i] && i < end)
	{
		res += get_index(base, str[i]) * pwr(basesize, end - i);
		i++;
	}
	return (res);
}

int	atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int	start;
	int res;

	i = 0;
	sign = 1;
	if (!ft_check_error(base))
		return (0);
	while (((str[i] > 8 && str[i] < 14) || str[i] == ' '))
		i++;
	while (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? sign *= -1 : sign;
	start = i;
	while (get_index(base, str[i]) >= 0)
	{
		i++;
	}
	res = ft_convert_base(str, base, start, i);
	return (res * sign);
}

int		test_atoi_base(char *str, char *base)
{
	int		res1;
	int		res2;

	res1 = ft_atoi_base(str, base);
	res2 = atoi_base(str, base);
	printf("string: |%s|\nbase  : |%s|\n",str, base);
	printf("ft_atoi_base: %d\n", res1);
	printf("vs atoi_base: %d\n", res2);
	return (res1 == res2);
}

void	lst_print(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", lst->data);
		lst = lst->next;
	}
}

int	rst(int	res)
{
	if (res == 0)
		printf("\033[0;31mKO\n");
	else
		printf("\033[0;32mOK\n");
	printf("\033[0m\n");
	return (res);
}

void		list_testing(void)
{
	t_list	*lst;

	printf("### INIT LIST ###\n");
	lst = ft_create_elem(strdup("E"));
	lst_print(lst);
	printf("#################\n");

	printf("\n### PUSH \"C\" FRONT ###\n");
	ft_list_push_front(&lst, strdup("C"));
	lst_print(lst);
	printf("#################\n");

	printf("\n### PUSH \"B\" then \"A\" FRONT ###\n");
	ft_list_push_front(&lst, strdup("B"));
	ft_list_push_front(&lst, strdup("A"));
	lst_print(lst);
	printf("#################\n");

	printf("\n### LIST SIZE ###\n");
	printf(">%d\n", ft_list_size(lst));
	printf("#################\n");

	printf("\n### PUSH \"D\" FRONT ###\n");
	ft_list_push_front(&lst, strdup("D"));
	lst_print(lst);
	printf("#################\n");

	printf("\n### LIST SIZE ###\n");
	printf(">%d\n", ft_list_size(lst));
	printf("#################\n");

	printf("\n### LIST SORT ###\n");
	ft_list_sort(&lst, &strcmp);
	lst_print(lst);
	printf("#################\n");

	printf("\n### LIST REMOVE IF (== E) ###\n");
	ft_list_remove_if(&lst, "E", &strcmp, &free);
	lst_print(lst);
	printf("#################\n");

	printf("\n### LIST REMOVE IF (== C) ###\n");
	ft_list_remove_if(&lst, "C", &strcmp, &free);
	lst_print(lst);
	printf("#################\n");
	
	printf("\n### LIST REMOVE IF (== A) ###\n");
	ft_list_remove_if(&lst, "A", &strcmp, &free);
	lst_print(lst);
	printf("#################\n");

	printf("\n### PUSH \"Z\" FRONT ###\n");
	ft_list_push_front(&lst, strdup("Z"));
	lst_print(lst);
	printf("#################\n");
	
	printf("\n### LIST SORT ###\n");
	ft_list_sort(&lst, &strcmp);
	lst_print(lst);
	printf("#################\n");
}

int		main(void)
{
	printf("### ATOI_BASE ###\n");
	rst(test_atoi_base("10A1", "0123456789ABCDEF"));
	rst(test_atoi_base("\t10A1", "0123456789ABCDEF"));
	rst(test_atoi_base("   ---10A1", "0123456789ABCDEF"));
	rst(test_atoi_base("-+-10A1", "0123456789ABCDEF"));
	rst(test_atoi_base("101010", "01"));
	rst(test_atoi_base("7524", "0123456789"));
	rst(test_atoi_base("7524", "01234056789"));
	rst(test_atoi_base("7524", "01234i+56789"));
	rst(test_atoi_base("7524", "012345-6789"));
	rst(test_atoi_base("7524", "012345 6789"));

	printf("### LIST ###\n");
	list_testing();
	return (0);
}

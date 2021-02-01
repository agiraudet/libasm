/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:26:20 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/01 13:52:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libtest.h"

void	print_lst(t_list *lst)
{
	printf(">\n");
	while (lst)
	{
		printf("%s\n", lst->data);
		lst = lst->next;
	}
	printf(">\n");
}

int	cmpl(void *c1, void *c2)
{
	return ((char*)c1 - (char*)c2);
}

int	main(void)
{
	t_list	l1;
	t_list	l2;
	t_list	*ls;

	ls = &l1;
	l1.data = "C";
	l2.data = "D";
	l1.next = &l2;
	l2.next = 0;
	printf("---init list---\n");
	print_lst(ls);
	printf("---------------\n\n");


	printf("---add elem---\n");
	l2.next = ft_create_elem("B");
	printf("%p\n", l2.next->next);
	print_lst(ls);
	printf("---------------\n\n");

	printf("---swap---\n");
	ft_list_swap(&l1);
	print_lst(ls);
	printf("---------------\n\n");

	printf("---push front---\n");
	ft_list_push_front(&ls, "A");
	print_lst(ls);
	printf("---------------\n\n");

	printf("---list size---\n");
	printf("%d\n", ft_list_size(ls));
	printf("---------------\n\n");

	printf("---list sort---\n");
	ft_list_sort(&ls, &ft_strcmp);
	print_lst(ls);
	printf("---------------\n\n");
	return (0);
}

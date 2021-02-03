/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:26:20 by agiraude          #+#    #+#             */
/*   Updated: 2021/02/03 13:44:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libasm.h"

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

int	main(void)
{
	t_list	l1;
	t_list	l2;
	t_list	*ls;

	ls = &l1;
	l1.data = ft_strdup("C");
	l2.data = ft_strdup("D");
	l1.next = &l2;
	l2.next = 0;
	printf("---init list---\n");
	print_lst(ls);
	printf("---------------\n\n");


	printf("---add elem---\n");
	l2.next = ft_create_elem(ft_strdup("B"));
	printf("%p\n", l2.next->next);
	print_lst(ls);
	printf("---------------\n\n");

	printf("---push front(x3)---\n");
	ft_list_push_front(&ls, ft_strdup("A"));
	ft_list_push_front(&ls, ft_strdup("F"));
	ft_list_push_front(&ls, ft_strdup("E"));
	print_lst(ls);
	printf("---------------\n\n");

	printf("---list size---\n");
	printf("%d\n", ft_list_size(ls));
	printf("---------------\n\n");

	printf("---list sort---\n");
	ft_list_sort(&ls, &ft_strcmp);
	print_lst(ls);
	printf("---------------\n\n");

	printf("---remove if (== E)---\n");
	ft_list_remove_if(&ls, "F", &ft_strcmp, &free); 
	print_lst(ls);
	printf("---------------\n");

	return (0);
}

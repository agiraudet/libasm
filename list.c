/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:26:20 by agiraude          #+#    #+#             */
/*   Updated: 2021/01/26 18:10:54 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libtest.h"

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", lst->data);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	l1;
	t_list	l2;
	t_list	*ls;

	ls = &l1;
	l1.data = "hello";
	l2.data = "world!";
	l1.next = &l2;
	l2.next = 0;
	print_lst(ls);


	printf("\n");
	l2.next = ft_create_elem(" !");
	print_lst(ls);

	printf("\n");
	ft_list_push_front(&ls, "test");
	print_lst(ls);

	printf("\n%d\n\n", ft_list_size(ls));
	return (0);
}

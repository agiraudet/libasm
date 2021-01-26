/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:26:20 by agiraude          #+#    #+#             */
/*   Updated: 2021/01/26 16:11:45 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libtest.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("wrong arg\n");
		return (0);
	}
	printf("%d\n", ft_atoi(argv[1], argv[2]));
	return (0);
}

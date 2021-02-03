/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:16:36 by user42            #+#    #+#             */
/*   Updated: 2021/02/03 13:52:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libasm.h"

int		test_atoi_base(void)
{
	int		i;
	char	*str[] = {"   ++---45",
					"   ---bb",
					"\v+42",
					"\t+-11101",
					"  \r  -+00801",
					" +4257",
					"10A1",
					"",
					" +  +54",
					"   134ertyh",
	printf("%s is %d\n", ft_atoi_base(str, base));
	return (1);
}

int		bonus(void)
{
	test_atoi_base(

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 23:27:11 by agiraude          #+#    #+#             */
/*   Updated: 2021/01/26 18:10:42 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <errno.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
ssize_t	ft_write(int fd, const void *buf, size_t count); 
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *s, const char *base);
int		ft_getindex(char c, const char *base);

t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **list, void *data);
int		ft_list_size(t_list *list);

#endif

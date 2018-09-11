/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_strpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 10:46:21 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:11:35 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_push(t_ls *l, char *s)
{
	while (*s)
	{
		if (l->ibuf < BUFF_SIZE)
		{
			l->buffer[l->ibuf] = *s;
			l->ibuf++;
			s++;
		}
		else
			ls_buffer_print(l);
	}
}

void	ls_push_column(t_ls *l, char *str, int max)
{
	char	buffer[max + 1];
	int		i;

	i = 0;
	while (str[i] && i < max)
	{
		buffer[i] = str[i];
		i++;
	}
	while (i < max)
		buffer[i++] = ' ';
	buffer[i] = 0;
	ls_push(l, buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 14:16:54 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:11:58 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_pushchr(t_ls *l, char c)
{
	if (l->ibuf < BUFF_SIZE)
	{
		l->buffer[l->ibuf] = c;
		l->ibuf++;
	}
	else
	{
		ls_buffer_print(l);
		l->buffer[l->ibuf] = c;
		l->ibuf++;
	}
}

void	ls_npush(t_ls *l, char *s, int n)
{
	if (s)
	{
		while (*s && n)
		{
			if (l->ibuf < BUFF_SIZE)
			{
				l->buffer[l->ibuf] = *s;
				l->ibuf++;
				s++;
				n--;
			}
			else
				ls_buffer_print(l);
		}
	}
}

void	ls_push_nbr(t_ls *l, uintmax_t n)
{
	if (n > 9)
	{
		ls_push_nbr(l, n / 10);
		ls_push_nbr(l, n % 10);
	}
	else
	{
		ls_pushchr(l, n + 48);
	}
}

void	ls_push_min(t_ls *l, char *s, uintmax_t min)
{
	uintmax_t n;

	n = 0;
	while (*s)
	{
		if (l->ibuf < BUFF_SIZE)
		{
			l->buffer[l->ibuf] = *s;
			l->ibuf++;
			s++;
			n++;
		}
		else
			ls_buffer_print(l);
	}
	while (n < min)
	{
		ls_pushchr(l, ' ');
		n++;
	}
}

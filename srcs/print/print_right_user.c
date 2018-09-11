/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_right_user.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:40:40 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:15:56 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	putcolor(t_ls *ls)
{
	if (ls->opt & G_FLAG)
		ls_push(ls, "\e[31m\e[1m");
}

void		print_right_user(t_ls *ls, t_lst_file *f)
{
	putcolor(ls);
	(f->data.stat.st_mode & S_IRUSR) ?
		ls_pushchr(ls, 'r') : ls_pushchr(ls, '-');
	(f->data.stat.st_mode & S_IWUSR) ?
		ls_pushchr(ls, 'w') : ls_pushchr(ls, '-');
	if (f->data.stat.st_mode & S_IXUSR)
	{
		(f->data.stat.st_mode & S_ISUID) ?
			ls_pushchr(ls, 's') : ls_pushchr(ls, 'x');
	}
	else
	{
		(f->data.stat.st_mode & S_ISUID) ?
			ls_pushchr(ls, 'S') : ls_pushchr(ls, '-');
	}
}

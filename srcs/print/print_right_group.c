/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_right_group.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:40:26 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:14:26 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	putcolor(t_ls *ls)
{
	if (ls->opt & G_FLAG)
		ls_push(ls, "\e[92m");
}

void		print_right_group(t_ls *ls, t_lst_file *f)
{
	putcolor(ls);
	if (f->data.stat.st_mode & S_IRGRP)
		ls_pushchr(ls, 'r');
	else
		ls_pushchr(ls, '-');
	if (f->data.stat.st_mode & S_IWGRP)
		ls_pushchr(ls, 'w');
	else
		ls_pushchr(ls, '-');
	if (f->data.stat.st_mode & S_IXGRP)
	{
		(f->data.stat.st_mode & S_ISGID) ?
			ls_pushchr(ls, 's') : ls_pushchr(ls, 'x');
	}
	else
	{
		(f->data.stat.st_mode & S_ISGID) ?
			ls_pushchr(ls, 'S') : ls_pushchr(ls, '-');
	}
}

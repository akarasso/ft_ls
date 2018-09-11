/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_right_other.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:40:51 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:15:25 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	putcolor(t_ls *ls)
{
	if (ls->opt & G_FLAG)
		ls_push(ls, "\e[36m");
}

void		print_right_other(t_ls *ls, t_lst_file *f)
{
	putcolor(ls);
	(f->data.stat.st_mode & S_IROTH) ?
		ls_pushchr(ls, 'r') : ls_pushchr(ls, '-');
	(f->data.stat.st_mode & S_IWOTH) ?
		ls_pushchr(ls, 'w') : ls_pushchr(ls, '-');
	if (f->data.stat.st_mode & S_IXOTH)
	{
		(f->data.stat.st_mode & S_ISVTX) ?
			ls_pushchr(ls, 't') : ls_pushchr(ls, 'x');
	}
	else
	{
		(f->data.stat.st_mode & S_IXOTH) ?
			ls_pushchr(ls, 'T') : ls_pushchr(ls, '-');
	}
}

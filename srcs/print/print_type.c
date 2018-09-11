/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:39:07 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:11:01 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	put_color(t_ls *ls)
{
	if (ls->opt & G_FLAG)
		ls_push(ls, "\e[94m\e[1m");
}

void		print_type(t_ls *ls, t_lst_file *f)
{
	put_color(ls);
	if ((f->data.stat.st_mode & S_IFMT) == S_IFREG)
		ls_pushchr(ls, '-');
	else if ((f->data.stat.st_mode & S_IFMT) == S_IFCHR)
		ls_pushchr(ls, 'c');
	else if ((f->data.stat.st_mode & S_IFMT) == S_IFDIR)
		ls_pushchr(ls, 'd');
	else if ((f->data.stat.st_mode & S_IFMT) == S_IFBLK)
		ls_pushchr(ls, 'b');
	else if ((f->data.stat.st_mode & S_IFMT) == S_IFIFO)
		ls_pushchr(ls, 'p');
	else if ((f->data.stat.st_mode & S_IFMT) == S_IFLNK)
		ls_pushchr(ls, 'l');
	else if ((f->data.stat.st_mode & S_IFMT) == S_IFSOCK)
		ls_pushchr(ls, 's');
	else
		ls_pushchr(ls, '?');
}

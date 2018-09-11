/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:10:11 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 16:43:33 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		put_color(t_ls *ls, t_lst_file *file)
{
	char *ext_part;

	if (ls->opt & G_FLAG && (ext_part = ft_strlchr(file->data.name, '.')))
	{
		if (S_ISDIR(file->data.stat.st_mode))
			ls_push(ls, "\e[1m\e[96m");
		else if (ext_part)
		{
			if (!ft_strcmp(ext_part, ".o"))
				ls_push(ls, "\e[2m");
			else if (!ft_strcmp(ext_part, ".c") || !ft_strcmp(ext_part, ".h"))
				ls_push(ls, "\e[1m\e[32m");
			else if (!ft_strcmp(ext_part, ".sh"))
				ls_push(ls, "\e[1m\e[91m");
			else if (!ft_strcmp(ext_part, ".todo"))
				ls_push(ls, "\e[1m\e[93m");
			else if ((file->data.stat.st_mode & S_IFMT) == S_IFLNK)
				ls_push(ls, "\e[1m\e[94m");
			else if (file->data.stat.st_mode & S_IXUSR
				|| file->data.stat.st_mode & S_IXGRP
				|| file->data.stat.st_mode & S_IXOTH)
				ls_push(ls, "\e[1m\e[91m");
		}
	}
}

void			print_name(t_ls *ls, t_lst_file *file)
{
	put_color(ls, file);
	if (ls->opt & Q_FLAG)
		ls_push(ls, "\"");
	ls_push(ls, file->data.name);
	if (ls->opt & PP_FLAG && S_ISDIR(file->data.stat.st_mode))
		ls_push(ls, "/");
	else if (ls->opt & PP_FLAG || ls->opt & F_FLAG)
	{
		if (S_ISDIR(file->data.stat.st_mode))
			ls_push(ls, "/");
		else if (S_ISLNK(file->data.stat.st_mode))
			ls_push(ls, "@");
		else if ((S_IXUSR | S_IXGRP | S_IXOTH) & file->data.stat.st_mode)
			ls_push(ls, "*");
		else if ((file->data.stat.st_mode & S_IFMT) == S_IFSOCK)
			ls_push(ls, "=");
		else if ((file->data.stat.st_mode & S_IFMT) == S_IFIFO)
			ls_push(ls, "|");
	}
	if (ls->opt & Q_FLAG)
		ls_push(ls, "\"");
	if (ls->opt & G_FLAG)
		ls_push(ls, "\e[0m");
	print_sym_link(ls, file);
}

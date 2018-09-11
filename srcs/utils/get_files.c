/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 08:20:55 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 17:30:38 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		close_dir(t_ls *ls, t_grp *grp, DIR *dir)
{
	if (closedir(dir))
	{
		ls_push(ls, "Failed to closed dir:");
		ls_push(ls, grp->path);
		ls_push(ls, "\n");
	}
}

int				get_files(t_ls *ls, t_grp *grp)
{
	struct dirent	*ent;
	DIR				*dir;
	t_lst_file		*file;

	if ((dir = opendir(grp->path)))
	{
		while ((ent = readdir(dir)))
		{
			file = ls_lst_push(ls, grp, grp->path, ent->d_name);
			grp->nb_files++;
		}
		ls_lst_bubblesort(grp->files, ls->sort_fnc);
		close_dir(ls, grp, dir);
		return (1);
	}
	else
	{
		ls_push(ls, "ls: ");
		ls_push(ls, grp->path);
		ls_push(ls, ": ");
		ls_buffer_print(ls);
		perror(grp->path);
	}
	return (0);
}

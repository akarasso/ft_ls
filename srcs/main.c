/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:47:59 by root              #+#    #+#             */
/*   Updated: 2018/09/11 09:34:58 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			init_group(t_grp *grp)
{
	grp->path = 0;
	grp->files = 0;
	grp->last_entry = 0;
	grp->nb_files = 0;
	grp->st_size_max = 0;
	grp->st_nlink_max = 0;
	grp->max_len_name = 0;
	grp->passwd_size = 0;
	grp->group_size = 0;
	grp->total = 0;
	grp->passwd = 0;
	grp->group = 0;
}

static void		init(t_ls *ls)
{
	ls->ibuf = 0;
	ls->nb_path = 0;
	ls->nb_folder = 0;
	ls->opt = 0;
	ls->ret = 0;
	init_group(&ls->files);
	init_group(&ls->folders);
}

int				main(int argc, char **argv)
{
	t_ls		ls;
	t_lst_file	*lst_folder;

	init(&ls);
	if (parser(&ls, argc, argv))
	{
		ls_lst_bubblesort(ls.folders.files, ls.sort_fnc);
		ls_print_struct(&ls, &ls.files);
		lst_folder = ls.folders.files;
		while (lst_folder)
		{
			dprint_struct(&ls, ft_strdup(lst_folder->data.full_path));
			if (lst_folder->next)
				ls_push(&ls, "\n");
			lst_folder = lst_folder->next;
		}
	}
	ls_lst_free(ls.folders.files);
	ls_lst_free(ls.files.files);
	free_grp(&ls.files);
	free_grp(&ls.folders);
	ls_buffer_print(&ls);
	return (ls.ret);
}

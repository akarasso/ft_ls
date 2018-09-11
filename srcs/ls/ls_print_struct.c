/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:46:38 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 17:28:49 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_line_grp(t_ls *ls, t_grp *grp)
{
	t_lst_file	*file;
	int			clink_size;
	int			csize_size;

	csize_size = ft_nbr_len(grp->st_size_max) + 2;
	clink_size = ft_nbr_len(grp->st_nlink_max) + 1;
	file = grp->files;
	while (file)
	{
		if (!file->data.hidden)
		{
			print_rights(ls, file);
			print_clink(ls, file->data.stat.st_nlink, clink_size);
			print_grp_user(ls, grp, file);
			if ((file->data.stat.st_mode & S_IFMT) == S_IFCHR
					|| (file->data.stat.st_mode & S_IFMT) == S_IFBLK)
				print_min_maj(ls, file);
			else
				print_size(ls, file->data.stat.st_size, csize_size);
			print_date(ls, file);
			print_name(ls, file);
			ls_push(ls, "\n");
		}
		file = file->next;
	}
}

void		print_column_grp(t_ls *ls, t_grp *grp)
{
	t_lst_file *file;

	file = grp->files;
	while (file)
	{
		if (!file->data.hidden)
		{
			print_name(ls, file);
			if (ls->opt & C_FLAG && file->next)
				ls_push(ls, "  ");
			else if (ls->opt & MM_FLAG && file->next)
				ls_push(ls, ", ");
			else
				ls_push(ls, "\n");
		}
		file = file->next;
	}
}

void		ls_print_struct(t_ls *ls, t_grp *grp)
{
	if (grp->files)
	{
		if (ls->opt & LL_FLAG || ls->opt & GG_FLAG)
			print_line_grp(ls, grp);
		else
			print_column_grp(ls, grp);
	}
}

void		dprint_struct(t_ls *ls, char *path)
{
	t_grp		grp;
	t_lst_file	*tmp;

	init_group(&grp);
	grp.path = path;
	if (get_files(ls, &grp))
	{
		print_header(ls, &grp);
		ls_print_struct(ls, &grp);
		while (grp.files)
		{
			if (ls->opt & R_FLAG && S_ISDIR(grp.files->data.stat.st_mode) &&
				ft_strcmp(grp.files->data.name, ".")
				&& ft_strcmp(grp.files->data.name, "..") && ++ls->nb_folder)
			{
				ls_push(ls, "\n");
				dprint_struct(ls, get_fullpath(grp.path, grp.files->data.name));
			}
			tmp = grp.files;
			grp.files = grp.files->next;
			ls_lst_free_elem(&tmp);
		}
	}
	free_grp(&grp);
}

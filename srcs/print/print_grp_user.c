/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grp_user.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:59:58 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:12:38 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	put_color(t_ls *ls)
{
	if (ls->opt & G_FLAG)
		ls_push(ls, "\e[3m");
}

void		print_grp_user(t_ls *ls, t_grp *grp, t_lst_file *file)
{
	put_color(ls);
	if (!ls || !grp || !file)
		return ;
	if ((file->data.passwd = getpwuid(file->data.stat.st_uid))
		&& !(ls->opt & GG_FLAG))
	{
		ls_push(ls, " ");
		ls_push_column(ls, file->data.passwd->pw_name, grp->passwd_size);
	}
	if ((file->data.group = getgrgid(file->data.stat.st_gid)))
	{
		ls_push(ls, "  ");
		ls_push_column(ls, file->data.group->gr_name, grp->group_size);
	}
	if (ls->opt & G_FLAG)
		ls_push(ls, "\e[24m\e[2m");
}

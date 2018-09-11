/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:11:30 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 10:13:17 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_lst_free_elem(t_lst_file **file)
{
	if (*file)
	{
		if ((*file)->data.name)
		{
			free((*file)->data.name);
			(*file)->data.name = 0;
		}
		if ((*file)->data.full_path)
		{
			free((*file)->data.full_path);
			(*file)->data.full_path = 0;
		}
		free(*file);
		*file = 0;
	}
}

void	ls_lst_free(t_lst_file *file)
{
	t_lst_file *tmp;

	while (file)
	{
		tmp = file;
		file = file->next;
		ls_lst_free_elem(&tmp);
	}
}

void	free_grp(t_grp *grp)
{
	if (grp)
	{
		if (grp->path)
		{
			free(grp->path);
			grp->path = 0;
		}
	}
}

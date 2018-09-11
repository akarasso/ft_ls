/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sym_link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:00:58 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 15:26:03 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_sym_link(t_ls *ls, t_lst_file *file)
{
	char	buffer[4096];
	int		ret;

	if (ls->opt & LL_FLAG || ls->opt & GG_FLAG)
	{
		if ((file->data.stat.st_mode & S_IFMT)
			== S_IFLNK && !(ls->opt & L_FLAG))
		{
			if ((ret = readlink(file->data.full_path, buffer, 4096)) > -1)
			{
				ls_push(ls, " -> ");
				buffer[ret] = 0;
				ls_push(ls, buffer);
			}
		}
	}
}

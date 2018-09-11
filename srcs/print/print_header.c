/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:43:51 by akarasso          #+#    #+#             */
/*   Updated: 2018/09/11 09:36:58 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_header(t_ls *ls, t_grp *grp)
{
	if (ls->nb_folder > 0)
	{
		if (ls->opt & G_FLAG)
			ls_push(ls, "\e[97m\e[3m\e[1m\e[4m");
		ls_push(ls, grp->path);
		(ls->opt & G_FLAG) ? ls_push(ls, ":\e[0m\n") : ls_push(ls, ":\n");
	}
	if ((ls->opt & LL_FLAG || ls->opt & GG_FLAG) && grp->nb_files > 2)
	{
		(ls->opt & G_FLAG) ?\
			ls_push(ls, "\e[96mtotal ") : ls_push(ls, "total ");
		ls_push_nbr(ls, grp->total);
		(ls->opt & G_FLAG) ? ls_push(ls, "\e[0m\n") : ls_push(ls, "\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_acl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:59:26 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:09:45 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	putcolor(t_ls *ls)
{
	if (ls->opt & G_FLAG)
		ls_push(ls, "\e[92m");
}

void		print_acl(t_ls *ls, t_lst_file *file)
{
	putcolor(ls);
	ls_pushchr(ls, file->data.extra);
}

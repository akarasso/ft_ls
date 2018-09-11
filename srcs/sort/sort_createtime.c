/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_createtime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 15:35:45 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:09:24 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_createtime(t_lst_file *f1, t_lst_file *f2)
{
	if (!f1 || !f2)
		return (0);
	if (f2->data.stat.st_birthtimespec.tv_sec ==
		f1->data.stat.st_birthtimespec.tv_sec)
		return (sort_ascii(f1, f2));
	return (f2->data.stat.st_birthtimespec.tv_sec -
		f1->data.stat.st_birthtimespec.tv_sec);
}

int		rsort_createtime(t_lst_file *f1, t_lst_file *f2)
{
	return (-sort_createtime(f1, f2));
}

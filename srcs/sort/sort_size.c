/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:51:25 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:08:59 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_size(t_lst_file *f1, t_lst_file *f2)
{
	if (!f1 || !f2)
		return (0);
	if (f1->data.stat.st_size == f2->data.stat.st_size)
		return (sort_ascii(f1, f2));
	return (f2->data.stat.st_size - f1->data.stat.st_size);
}

int		rsort_size(t_lst_file *f1, t_lst_file *f2)
{
	return (-sort_size(f1, f2));
}

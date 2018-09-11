/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_modtime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 08:51:53 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:08:51 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_modtime(t_lst_file *f1, t_lst_file *f2)
{
	if (!f1 || !f2)
		return (0);
	if (f1->data.time_modified == f2->data.time_modified)
		return (sort_ascii(f1, f2));
	return (f2->data.time_modified - f1->data.time_modified);
}

int		rsort_modtime(t_lst_file *f1, t_lst_file *f2)
{
	return (-sort_modtime(f1, f2));
}

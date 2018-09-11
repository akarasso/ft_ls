/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_accesstime.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 08:51:53 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:09:02 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_accesstime(t_lst_file *f1, t_lst_file *f2)
{
	if (!f1 || !f2)
		return (0);
	if (f2->data.time_access == f1->data.time_access)
		return (sort_ascii(f1, f2));
	return (f2->data.time_access - f1->data.time_access);
}

int		rsort_accesstime(t_lst_file *f1, t_lst_file *f2)
{
	return (-sort_accesstime(f1, f2));
}

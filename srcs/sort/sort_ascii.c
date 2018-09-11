/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 08:46:22 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:09:12 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		sort_ascii(t_lst_file *f1, t_lst_file *f2)
{
	int i;

	if (!f1 || !f2)
		return (0);
	i = 0;
	while (f1->data.name[i] && f1->data.name[i] == f2->data.name[i])
		i++;
	return (f1->data.name[i] - f2->data.name[i]);
}

int		rsort_ascii(t_lst_file *f1, t_lst_file *f2)
{
	return (-sort_ascii(f1, f2));
}

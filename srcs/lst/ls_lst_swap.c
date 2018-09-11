/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:50:11 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:01:34 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_dataswap(t_lst_data *d1, t_lst_data *d2)
{
	t_lst_data tmp;

	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}

void		ls_lst_swap(t_lst_file *file1, t_lst_file *file2)
{
	ft_dataswap(&file1->data, &file2->data);
}

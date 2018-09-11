/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_bubblesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 08:37:29 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 17:59:19 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_lst_bubblesort(t_lst_file *lst, int (*f)(t_lst_file *, t_lst_file*))
{
	if (!lst || !f)
		return ;
	while (lst->next)
	{
		if (f(lst, lst->next) > 0)
		{
			ls_lst_swap(lst, lst->next);
			if (lst->prev)
				lst = lst->prev;
		}
		else
			lst = lst->next;
	}
}

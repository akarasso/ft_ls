/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:28:12 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:28:31 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_rights(t_ls *ls, t_lst_file *file)
{
	print_type(ls, file);
	print_right_user(ls, file);
	print_right_group(ls, file);
	print_right_other(ls, file);
	print_acl(ls, file);
}

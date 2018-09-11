/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:46:06 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 16:57:27 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		parser(t_ls *ls, int argc, char **argv)
{
	if (!parse_options(ls, argc, argv))
		return (0);
	if (!parse_files(ls, argc, argv))
		return (0);
	return (1);
}

void	print_usage(t_ls *ls, char *valid, char *argv)
{
	ls_push(ls, "ls: illegal option -- ");
	ls_push(ls, argv);
	ls_push(ls, "\n");
	ls_push(ls, "usage: ls [-");
	ls_push(ls, valid);
	ls_push(ls, "]\n");
}

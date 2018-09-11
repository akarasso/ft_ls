/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:46:25 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 17:36:56 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	norm(t_ls *ls, char c)
{
	if (c == 'u')
		ls->opt ^= ls_pow('c' - 'A');
	if (c == 'c')
		ls->opt ^= ls_pow('u' - 'A');
	if (c == 'C')
		ls->opt ^= ls_pow('l' - 'A');
	if (c == 'l')
		ls->opt ^= ls_pow('C' - 'A');
}

int		check_opt(t_ls *ls, char *argv)
{
	char	*valid;
	int		i;

	i = 0;
	valid = "LCSTURGQFlartumpgf";
	argv++;
	while (argv[i])
	{
		if (ft_strchr(valid, argv[i]))
		{
			norm(ls, argv[i]);
			ls->opt |= ls_pow(argv[i] - 'A');
		}
		else
		{
			ls->ret = 1;
			print_usage(ls, valid, argv);
			return (0);
		}
		i++;
	}
	return (1);
}

void	select_sort_fnc(t_ls *ls)
{
	if (ls->opt & FF_FLAG)
		ls->sort_fnc = 0;
	else if (ls->opt & TT_FLAG && ls->opt & RR_FLAG)
		ls->sort_fnc = rsort_modtime;
	else if (ls->opt & TT_FLAG && ls->opt & UU_FLAG && ls->opt & RR_FLAG)
		ls->sort_fnc = rsort_accesstime;
	else if (ls->opt & TT_FLAG && ls->opt & U_FLAG && ls->opt & RR_FLAG)
		ls->sort_fnc = rsort_createtime;
	else if (ls->opt & S_FLAG && ls->opt & RR_FLAG)
		ls->sort_fnc = rsort_size;
	else if (ls->opt & RR_FLAG)
		ls->sort_fnc = rsort_ascii;
	else if (ls->opt & TT_FLAG && ls->opt & UU_FLAG)
		ls->sort_fnc = sort_accesstime;
	else if (ls->opt & TT_FLAG && ls->opt & U_FLAG)
		ls->sort_fnc = sort_createtime;
	else if (ls->opt & S_FLAG)
		ls->sort_fnc = sort_size;
	else if (ls->opt & TT_FLAG)
		ls->sort_fnc = sort_modtime;
	else
		ls->sort_fnc = sort_ascii;
}

int		parse_options(t_ls *ls, int argc, char **argv)
{
	int i;
	int end_arg;

	end_arg = 0;
	i = 1;
	while (i < argc)
	{
		if (!end_arg && !ft_strcmp("--", argv[i]))
			end_arg = 1;
		else if (!end_arg && argv[i][0] && argv[i][1]
			&& argv[i][0] == '-' && argv[i][1] != '-')
		{
			if (!check_opt(ls, argv[i]))
				return (0);
		}
		else
			end_arg = 1;
		i++;
	}
	select_sort_fnc(ls);
	return (1);
}

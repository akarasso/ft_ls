/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:46:34 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 17:36:38 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_last_char(char *str, char c)
{
	while (*str)
		str++;
	if (*(str - 1) == c)
		return (1);
	return (0);
}

t_lst_file	*push_sym_lnk(t_ls *ls, char *path)
{
	t_lst_file	*elem;

	elem = 0;
	if (ls->opt & LL_FLAG)
	{
		if (check_last_char(path, '/') || ls->opt & L_FLAG)
		{
			elem = ls_lst_push(ls, &ls->folders, path, "");
			ls->nb_folder++;
		}
		else
			elem = ls_lst_push(ls, &ls->files, 0, path);
	}
	else
	{
		elem = ls_lst_push(ls, &ls->folders, path, "");
		ls->nb_folder++;
	}
	return (elem);
}

void		push(t_ls *ls, char *path)
{
	struct stat	st;
	t_lst_file	*elem;

	if (lstat(path, &st) >= 0)
	{
		if (S_ISLNK(st.st_mode))
			elem = push_sym_lnk(ls, path);
		else if (S_ISDIR(st.st_mode) && ++ls->nb_folder)
			elem = ls_lst_push(ls, &ls->folders, 0, path);
		else
			elem = ls_lst_push(ls, &ls->files, 0, path);
		elem->data.stat = st;
	}
	else
	{
		ls_push(ls, "ls: ");
		ls_push(ls, path);
		ls_push(ls, ": ");
		ls_buffer_print(ls);
		perror("");
	}
}

int			parse_files(t_ls *ls, int argc, char **argv)
{
	int i;
	int end_arg;

	end_arg = 0;
	i = 1;
	while (i < argc)
	{
		if (!end_arg && !ft_strcmp("--", argv[i]))
			end_arg = 1;
		else if (!(!end_arg && argv[i][0] && argv[i][1]
			&& argv[i][0] == '-' && argv[i][1] != '-'))
		{
			push(ls, argv[i]);
			ls->nb_path++;
			end_arg = 1;
		}
		i++;
	}
	if (ls->nb_path == 0)
	{
		ls_lst_push(ls, &ls->folders, 0, ".");
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 17:00:39 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 15:33:58 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_mt6(t_ls *ls, char *str_time)
{
	ls_push(ls, " ");
	if (ls->opt & T_FLAG)
		ls_npush(ls, str_time + 4, 20);
	else
	{
		ls_npush(ls, str_time + 4, 6);
		ls_push(ls, " ");
		ls_npush(ls, str_time + 19, 5);
	}
	ls_push(ls, " ");
}

void	print_date(t_ls *ls, t_lst_file *f)
{
	char			*str_time;
	struct timespec *cmp_time;
	time_t			crt_time;

	crt_time = time(0);
	cmp_time = (ls->opt & U_FLAG) ? &f->data.stat.st_birthtimespec
		: &f->data.stat.st_mtimespec;
	str_time = (ls->opt & U_FLAG) ? ctime(&f->data.stat.st_birthtimespec.tv_sec)
		: ctime(&f->data.stat.st_mtimespec.tv_sec);
	if (!str_time)
		return ;
	if (cmp_time->tv_sec > crt_time
		|| cmp_time->tv_sec + 15552000 < crt_time)
		print_mt6(ls, str_time);
	else
	{
		ls_push(ls, " ");
		if (ls->opt & T_FLAG)
			ls_npush(ls, str_time + 4, 20);
		else
			ls_npush(ls, str_time + 4, 12);
		ls_push(ls, " ");
	}
	if (ls->opt & G_FLAG)
		ls_push(ls, "\e[0m");
}

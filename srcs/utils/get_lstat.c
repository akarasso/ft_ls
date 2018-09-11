/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:33:33 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 17:19:40 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	get_lstat(t_grp *path, t_lst_file *file)
{
	if (lstat(file->data.full_path, &file->data.stat) != -1)
	{
		if (!file->data.hidden)
		{
			path->total += file->data.stat.st_blocks;
			file->data.time_modified = file->data.stat.st_mtimespec.tv_sec;
			file->data.time_access = file->data.stat.st_atimespec.tv_sec;
			if (((file->data.stat.st_mode & S_IFMT) == S_IFCHR
				|| (file->data.stat.st_mode & S_IFMT)
				== S_IFBLK) && path->st_size_max < 10000000)
			{
				path->st_size_max = 10000000;
			}
			if (file->data.stat.st_size > path->st_size_max)
				path->st_size_max = file->data.stat.st_size;
			if (file->data.stat.st_nlink > path->st_nlink_max)
				path->st_nlink_max = file->data.stat.st_nlink;
			if (file->data.name_size > path->max_len_name)
				path->max_len_name = file->data.name_size;
		}
		return (1);
	}
	return (0);
}

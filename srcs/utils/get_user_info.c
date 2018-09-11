/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_user_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:47:44 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 09:49:19 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_user_info(t_grp *grp, t_lst_file *file)
{
	int				log_size;
	int				grp_size;
	struct passwd	*pwuid;
	struct group	*grgid;

	if ((pwuid = getpwuid(file->data.stat.st_uid)))
	{
		log_size = ft_strlen(pwuid->pw_name);
		if (!file->data.hidden && grp->passwd_size < log_size)
			grp->passwd_size = log_size;
	}
	if ((grgid = getgrgid(file->data.stat.st_gid)))
	{
		grp_size = ft_strlen(grgid->gr_name);
		if (!file->data.hidden && grp->group_size < grp_size)
			grp->group_size = grp_size;
	}
}

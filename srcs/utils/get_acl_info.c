/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_acl_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:38:22 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 09:10:08 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_acl_info(t_lst_file *file)
{
	acl_t		acl;
	acl_entry_t	dummy;
	ssize_t		xattr;

	file->data.extra = ' ';
	acl = acl_get_link_np(file->data.full_path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = 0;
	}
	xattr = listxattr(file->data.full_path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		file->data.extra = '@';
	else if (acl != 0)
		file->data.extra = '+';
	else
		file->data.extra = ' ';
	free(acl);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_get_full_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 08:48:51 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/24 18:36:46 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_fullpath(char *path, char *filename)
{
	char	*new;
	char	*ptr;
	int		dlen;

	dlen = 2;
	dlen += (path) ? ft_strlen(path) : 0;
	dlen += (filename) ? ft_strlen(filename) : 0;
	if (!(new = (char *)malloc(dlen)))
		return (0);
	ptr = new;
	if (path)
	{
		while (*path)
			*ptr++ = *path++;
	}
	if (path && filename && *(path - 1) != '/')
		*ptr++ = '/';
	if (filename)
	{
		while (*filename)
			*ptr++ = *filename++;
	}
	*ptr = 0;
	return (new);
}

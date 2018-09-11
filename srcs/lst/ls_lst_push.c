/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_lst_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:03:48 by root              #+#    #+#             */
/*   Updated: 2018/05/25 10:29:20 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_strdup(char *str)
{
	char *new;
	char *ptr;

	if (!str)
		return (0);
	if (!(new = (char*)malloc(ft_strlen(str) + 1)))
		return (NULL);
	ptr = new;
	while (*str)
	{
		*ptr = *str;
		ptr++;
		str++;
	}
	*ptr = 0;
	return (new);
}

static t_lst_file	*ls_lst_new(char *path, char *name)
{
	t_lst_file *new;

	new = (t_lst_file *)malloc(sizeof(t_lst_file));
	if (!new)
		return (0);
	if (!(new->data.name = ft_strdup(name)))
	{
		free(new);
		return (0);
	}
	if (!(new->data.full_path = get_fullpath(path, name)))
	{
		free(new->data.name);
		free(new);
		return (0);
	}
	new->data.name_size = ft_strlen(name);
	new->data.passwd = 0;
	new->data.group = 0;
	new->data.hidden = 0;
	new->next = 0;
	new->prev = 0;
	return (new);
}

t_lst_file			*ls_lst_push(t_ls *ls, t_grp *grp, char *path, char *name)
{
	t_lst_file *new;

	if (!(new = ls_lst_new(path, name)))
		return (0);
	if (*new->data.name == '.' && !(ls->opt & AA_FLAG || ls->opt & FF_FLAG))
		new->data.hidden = 1;
	if (!get_lstat(grp, new))
	{
		ls_lst_free_elem(&new);
		return (0);
	}
	if (ls->opt & LL_FLAG || ls->opt & GG_FLAG)
	{
		get_user_info(grp, new);
		get_acl_info(new);
	}
	if (!grp->files)
		grp->files = new;
	else
	{
		grp->last_entry->next = new;
		new->prev = grp->last_entry;
	}
	grp->last_entry = new;
	return (new);
}

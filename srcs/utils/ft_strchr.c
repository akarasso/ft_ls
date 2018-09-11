/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:11:06 by root              #+#    #+#             */
/*   Updated: 2018/05/24 18:24:32 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}

char	*ft_strlchr(char *s, char c)
{
	char *ret;

	ret = s;
	while (*s)
	{
		if (*s == c)
			ret = s;
		s++;
	}
	return (ret);
}

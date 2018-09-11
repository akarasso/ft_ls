/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 10:40:30 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/25 17:19:48 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <errno.h>
# include "ft_flag.h"
# define BUFF_SIZE 4096

typedef struct	s_lst_data
{
	char				*name;
	char				*full_path;
	int					name_size;
	char				hidden;
	char				extra;
	struct stat			stat;
	struct passwd		*passwd;
	struct group		*group;
	time_t				time_modified;
	time_t				time_access;
}				t_lst_data;

typedef struct	s_lst_file
{
	t_lst_data			data;
	struct s_lst_file	*prev;
	struct s_lst_file	*next;
}				t_lst_file;

typedef struct	s_grp
{
	char			*path;
	struct stat		stat;
	struct passwd	*passwd;
	struct group	*group;
	int				nb_files;
	int				st_size_max;
	size_t			st_nlink_max;
	int				passwd_size;
	int				group_size;
	int				max_len_name;
	int				total;
	t_lst_file		*last_entry;
	t_lst_file		*files;
}				t_grp;

typedef struct	s_ls
{
	long long	opt;
	int			nb_path;
	int			nb_folder;
	char		buffer[BUFF_SIZE];
	int			(*sort_fnc)(t_lst_file *, t_lst_file*);
	t_grp		files;
	t_grp		folders;
	int			ibuf;
	int			ret;
}				t_ls;

int				parser(t_ls *l, int argc, char **argv);
int				parse_options(t_ls *l, int argc, char **argv);
int				parse_files(t_ls *l, int argc, char **argv);
void			ls_print_struct(t_ls *ls, t_grp *grp);
void			dprint_struct(t_ls *ls, char *path);
void			init_group(t_grp *grp);

/*
** Print
*/
void			print_name(t_ls *ls, t_lst_file *file);
void			print_date(t_ls *ls, t_lst_file *file);
void			print_sym_link(t_ls *ls, t_lst_file *file);
void			print_type(t_ls *ls, t_lst_file *file);
void			print_right_user(t_ls *ls, t_lst_file *file);
void			print_right_group(t_ls *ls, t_lst_file *file);
void			print_right_other(t_ls *ls, t_lst_file *file);
void			print_acl(t_ls *ls, t_lst_file *file);
void			print_clink(t_ls *ls, int number, int s);
void			print_size(t_ls *ls, int number, int s);
void			print_min_maj(t_ls *ls, t_lst_file *file);
void			print_grp_user(t_ls *ls, t_grp *grp, t_lst_file *file);
void			print_rights(t_ls *ls, t_lst_file *file);
void			print_header(t_ls *ls, t_grp *grp);
void			print_usage(t_ls *ls, char *valid, char *argv);
/*
** Lst Files
*/

t_lst_file		*ls_lst_push(t_ls *ls, t_grp *grp, char *path, char *name);
void			ls_lst_bubblesort(t_lst_file *lst,
					int(*f)(t_lst_file *, t_lst_file*));
void			ls_lst_swap(t_lst_file *file1, t_lst_file *file2);
int				sort_ascii(t_lst_file *f1, t_lst_file *f2);
int				rsort_ascii(t_lst_file *f1, t_lst_file *f2);
int				sort_modtime(t_lst_file *f1, t_lst_file *f2);
int				rsort_modtime(t_lst_file *f1, t_lst_file *f2);
int				sort_createtime(t_lst_file *f1, t_lst_file *f2);
int				rsort_createtime(t_lst_file *f1, t_lst_file *f2);
int				sort_accesstime(t_lst_file *f1, t_lst_file *f2);
int				rsort_accesstime(t_lst_file *f1, t_lst_file *f2);
int				sort_size(t_lst_file *f1, t_lst_file *f2);
int				rsort_size(t_lst_file *f1, t_lst_file *f2);

/*
** Buffer
*/

void			ls_pushchr(t_ls *l, char c);
void			ls_push(t_ls *l, char *s);
void			ls_npush(t_ls *l, char *s, int n);
void			ls_push_min(t_ls *l, char *s, uintmax_t n);
void			ls_push_nbr(t_ls *l, uintmax_t nbr);
void			ls_push_column(t_ls *l, char *str, int size);
void			ls_buffer_print(t_ls *l);

/*
** Free
*/

void			ls_lst_free_elem(t_lst_file **file);
void			ls_lst_free(t_lst_file *file);
void			free_grp(t_grp *grp);

/*
** Util
*/

long long		ls_pow(unsigned int pow);
int				ft_strlen(char *s);
int				ft_strcmp(char *s1, char *s2);
int				ft_strcmp_ic(char *s1, char *s2);
int				ft_nbr_len(intmax_t i);
int				get_lstat(t_grp *path, t_lst_file *file);
int				get_files(t_ls *ls, t_grp *grp);
char			*ft_strdup(char *str);
char			*get_fullpath(char *path, char *filename);
char			*ft_strchr(char *s, char c);
char			*ft_strlchr(char *s, char c);
void			get_stat(t_grp *path, t_lst_file *file);
void			ls_push_file(t_ls *ls, t_lst_file *file);
void			get_user_info(t_grp *path, t_lst_file *file);
void			get_acl_info(t_lst_file *file);

#endif

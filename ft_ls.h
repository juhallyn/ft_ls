/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:36:00 by juhallyn          #+#    #+#             */
/*   Updated: 2017/07/27 12:43:40 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef enum s_bool
{
	false = 0,
	true = 1
}			bool;

typedef struct			s_path
{
	// struct s_path		*begin;
	struct stat			*buff;
	struct s_data		*data;
	struct s_path		*next;
}						t_path;

typedef struct			s_data
{
	char		*permission;
	nlink_t		hard_link;
	char		*owner;
	char		*group;
	off_t		file_size;
	char		*time;
	char		*d_name;
	blkcnt_t	blocks;
}						t_data;

typedef	struct			s_options
{
	bool	a_option;
	bool	R_option;
	bool	t_option;
	bool	l_option;
	bool	r_option;
}						t_ops;

// LS
void		print_list(t_path *list);
char		*creat_path(char *argv, char *d_name);

void 		ft_putentab(char *str);
blkcnt_t	all_blocks(t_path *list);
void		print_blocks(blkcnt_t blocks);

t_data		*init_data(struct stat *buff, struct dirent *sd);

/*
*	--	data for -l option--
*		--> data.c
*/

char		*permission(struct stat *buff);
char		*owner(struct stat *buff);
char		*group(struct stat *buff);
char		*ft_time(struct stat *buff);

/*
*	--	PARSING OPTIONS --
*		--> option.c
*/

int			error_option(char bad_option);
int			check_options(char *options);
t_ops		*init_to_false(t_ops *flags);
void		init_flags(char *options, t_ops **flags);
t_ops		parsing_option(int argc, char **argv);

/*
*	--	sort linked list --
*		--> sort.c
*/

void		insert_ascii(t_path **list, t_path *new);

/*
*	--	manage linked list and print_list --
*		--> list.c
*/

t_path		*add_head(t_path *list, t_data *data);
t_path		*create_node(t_data *data);
void		print_list(t_path *list);

/*
*	--	--> main.c
*/

char		*creat_path(char *argv, char *d_name);
t_path		*list_file(char *argv, t_ops ops);
t_path		*ft_init(struct dirent *sd, char *argv, t_ops ops, DIR *dir);


#endif

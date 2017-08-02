/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 12:48:33 by juhallyn          #+#    #+#             */
/*   Updated: 2017/06/23 16:02:51 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

static char	filetype(struct stat *buff)
{
	if (S_ISREG(buff->st_mode))
		return ('-');
	if (S_ISDIR(buff->st_mode))
		return ('d');
	if (S_ISCHR(buff->st_mode))
		return ('c');
	if (S_ISBLK(buff->st_mode))
		return ('b');
	if (S_ISFIFO(buff->st_mode))
		return ('p');
	if (S_ISLNK(buff->st_mode))
		return ('l');
	if (S_ISSOCK(buff->st_mode))
		return ('s');
	return ('\0');
}

void	print_permission(struct stat *buff)
{
	char	str[10];
	mode_t	owner;
	mode_t	group;
	mode_t	other;

	str[0] = filetype(buff);
	owner = buff->st_mode & S_IRWXU;
	group = buff->st_mode & S_IRWXG;
	other = buff->st_mode & S_IRWXO;
	str[1] = owner & S_IRUSR ? 'r' : '-';
	str[2] = owner & S_IWUSR ? 'w' : '-';
	str[3] = owner & S_IXUSR ? 'x' : '-'; 
	str[4] = group & S_IRGRP ? 'r' : '-'; 
	str[5] = group & S_IWGRP ? 'w' : '-'; 
	str[6] = group & S_IXGRP ? 'w' : '-'; 
	str[7] = other & S_IROTH ? 'r' : '-'; 
	str[8] = other & S_IWOTH ? 'w' : '-'; 
	str[9] = other & S_IXOTH ? 'x' : '-'; 
	write(1, str, 10);
}

void	print_owner(struct stat *buff)
{
	struct passwd *pwd;

	if ((pwd = getpwuid(buff->st_uid)) != NULL)
		ft_putstr(pwd->pw_name);
}

void	print_group(struct stat *buff)
{
	struct group *gp;

	if ((gp = getgrgid(buff->st_gid)) != NULL)
		ft_putstr(gp->gr_name);
}

void	print_time(struct stat *buff)
{
	char		*m_time;

	m_time = ctime(&buff->st_mtime);
	ft_putstr(ft_strsub(m_time, 4, 12));
}

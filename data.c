/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 15:04:40 by juhallyn          #+#    #+#             */
/*   Updated: 2017/08/14 17:09:48 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_ls.h"

char		filetype(struct stat *buff)
{
	if (S_ISREG(buff->st_mode))
		return ('-');
	else if (S_ISDIR(buff->st_mode))
		return ('d');
	else if (S_ISCHR(buff->st_mode))
		return ('c');
	else if (S_ISBLK(buff->st_mode))
		return ('b');
	else if (S_ISFIFO(buff->st_mode))
		return ('p');
	else if (S_ISLNK(buff->st_mode))
		return ('l');
	else if (S_ISSOCK(buff->st_mode))
		return ('s');
	return ('\0');
}

char		*permission(struct stat *buff)
{
	char		*str;
	mode_t		owner;
	mode_t		group;
	mode_t		other;

	if ((str = malloc(sizeof(char) * 11)) == NULL)
		return (NULL);
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
	str[10] = '\0';
	return (str);
}

char		*owner(struct stat *buff)
{
	struct passwd *pwd;

	if ((pwd = getpwuid(buff->st_uid)) != NULL)
		return (ft_strdup(pwd->pw_name));
	return (NULL);
}

char		*group(struct stat *buff)
{
	struct group *gp;

	if ((gp = getgrgid(buff->st_gid)) != NULL)
		return (gp->gr_name);
	return (NULL);
}

char		*ft_time(struct stat *buff)
{
	char		*m_time;

	m_time = ctime(&buff->st_mtime);
	return (ft_strsub(m_time, 4, 12));
}

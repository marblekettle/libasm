/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmans <bmans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 10:06:18 by bmans         #+#    #+#                 */
/*   Updated: 2020/07/22 11:50:37 by bmans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

extern int	errno;

/*
**	test_write: string to write | file to write to | number of bytes to write
**	test_read: file to read from | number of bytes to read
**	test_strlen: string to determine length of
**	test_strcpy: string to copy from | string to copy to | offset
**	test_strcmp: string to compare | other string to compare
**	test_strdup; string to duplicate
**	note: character '@' is interpreted as a null character, character '#' as
**	a newline;
*/

static void	test_write(const char *str, int nbytes)
{
	char	*newstr;
	char	buf[20];
	int		fd[2];
	int		err[2];
	int		len;
	int		match;

	newstr = strdup(str);
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (newstr[i] == '#')
			newstr[i] = '\n';
		else if (newstr[i] == '@')
			newstr[i] = '\0';
	}
	bzero(err, 8);
	system("touch tmp1.txt && touch tmp2.txt");
	printf("\033[1;37mTesting ft_write: %i bytes from \"%s\"\n", nbytes, str);
	printf("ft_write: ");
	fflush(stdout);
	ft_write(1, str, nbytes);
	printf("\n   write: ");
	fflush(stdout);
	write(1, str, nbytes);
	printf("\n");
	fd[0] = open("tmp1.txt", O_RDWR);
	fd[1] = open("tmp2.txt", O_RDWR);
	write(fd[0], newstr, nbytes);
	err[0] = errno;
	write(fd[1], newstr, nbytes);
	err[1] = errno;
	close(fd[0]);
	close(fd[1]);
	free(newstr);
	if (err[0] || err[1])
		printf("Error code:\nft_read: %i\n   read: %i\n", err[0], err[1]);
	system("diff tmp1.txt tmp2.txt | wc -c > tmp3.txt");
	fd[0] = open("tmp3.txt", O_RDWR);
	read(fd[0], buf, 19);
	buf[19] = '\0';
	match = atoi(buf);
	if (!match && err[0] == err[1])
		printf("\033[1;32mMATCH\n");
	else
		printf("\033[1;31mNO MATCH\n");
	system("rm -f tmp1.txt && rm -f tmp2.txt && rm -f tmp3.txt");
	printf("\n");
}

static void	test_read(const char *file, int nbytes)
{
	char	*ftrin;
	char	*rin;
	int		fd;
	int		err[2];

	bzero(err, 8);
	ftrin = malloc(abs(nbytes) + 1);
	bzero(ftrin, abs(nbytes) + 1);
	rin = malloc(abs(nbytes) + 1);
	bzero(rin, abs(nbytes) + 1);
	printf("\033[1;37mTesting ft_read: %i bytes from \"%s\"\n", nbytes, file);
	if (!strcmp(file, "ERROR"))
		fd = -1;
	else
		fd = open(file, O_RDWR);
	ft_read(fd, ftrin, nbytes);
	err[0] = errno;
	close(fd);
	if (!strcmp(file, "ERROR"))
		fd = -1;
	else
		fd = open(file, O_RDWR);
	read(fd, rin, nbytes);
	err[1] = errno;
	close(fd);
	for (int i = 0; i < nbytes; i++)
	{
		if (ftrin[i] == '\n')
			ftrin[i] = '#';
		else if (ftrin[i] == '\0')
			ftrin[i] = '@';
		if (rin[i] == '\n')
			rin[i] = '#';
		else if (rin[i] == '\0')
			rin[i] = '@';
	}
	printf("ft_read: ");
	fflush(stdout);
	write(1, ftrin, nbytes);
	printf("\n   read: ");
	fflush(stdout);
	write(1, rin, nbytes);
	printf("\n");
	if (err[0] || err[1])
		printf("Error code:\nft_read: %i\n   read: %i\n", err[0], err[1]);
	if (!strcmp(ftrin, rin) && err[0] == err[1])
		printf("\033[1;32mMATCH\n");
	else
		printf("\033[1;31mNO MATCH\n");
	printf("\n");
	free(ftrin);
	free(rin);
}

static void	test_strlen(const char* str)
{
	int		len[2];
	char	*newstr;

	len[1] = strlen(str);
	newstr = strdup(str);
	for (int i = 0; i < len[1]; i++)
	{
		if (newstr[i] == '#')
			newstr[i] = '\n';
		else if (newstr[i] == '@')
			newstr[i] = '\0';
	}
	printf("\033[1;37mTesting ft_strlen: length of \"%s\"\n", str);
	len[0] = ft_strlen(newstr);
	len[1] = strlen(newstr);
	printf("ft_strlen: %i\n   strlen: %i\n", len[0], len[1]);
	if (len[0] == len[1])
		printf("\033[1;32mMATCH\n");
	else
		printf("\033[1;31mNO MATCH\n");
	printf("\n");
	free(newstr);
}

static void	test_strcpy(const char *dst, const char* src, int off)
{
	char	*buf1;
	char	*buf2;
	char	*bufsrc;
	int		len;

	if (off < 0 || off > 99 - (int)strlen(src))
	{
		printf("\033[1;31mINVALID OFFSET\n\n");
		return ;
	}
	buf1 = malloc(100);
	bzero(buf1, 100);
	strcpy(buf1, dst);
	buf2 = malloc(100);
	bzero(buf2, 100);
	strcpy(buf2, dst);
	bufsrc = malloc(100);
	bzero(bufsrc, 100);
	strcpy(bufsrc, src);
	len = strlen(src) + off > strlen(dst) ? strlen(src) + off : strlen(dst);
	for (int i = 0; i < len; i++)
	{
		if (buf1[i] == '#')
			buf1[i] = '\n';
		else if (buf1[i] == '@')
			buf1[i] = '\0';
		if (buf2[i] == '#')
			buf2[i] = '\n';
		else if (buf2[i] == '@')
			buf2[i] = '\0';
		if (bufsrc[i] == '#')
			bufsrc[i] = '\n';
		else if (bufsrc[i] == '@')
			bufsrc[i] = '\0';
	}
	printf("\033[1;37mTesting ft_strcpy: \"%s\" into \"%s\" + %i\n", src, dst, off);
	ft_strcpy(buf1 + off, bufsrc);
	strcpy(buf2 + off, bufsrc);
	for (int i = 0; i < len; i++)
	{
		if (buf1[i] == '\n')
			buf1[i] = '#';
		else if (buf1[i] == '\0')
			buf1[i] = '@';
		if (buf2[i] == '\n')
			buf2[i] = '#';
		else if (buf2[i] == '\0')
			buf2[i] = '@';
		if (bufsrc[i] == '\n')
			bufsrc[i] = '#';
		else if (bufsrc[i] == '\0')
			bufsrc[i] = '@';
	}
	printf("ft_strcpy: %s\n   strcpy: %s\n", buf1, buf2);
	if (!strcmp(buf1, buf2))
		printf("\033[1;32mMATCH\n");
	else
		printf("\033[1;31mNO MATCH\n");
	free(buf1);
	free(buf2);
	free(bufsrc);
	printf("\n");
}

static void	test_strcmp(const char *s1, const char *s2)
{
	int		out[2];
	char	*buf1;
	char	*buf2;

	buf1 = strdup(s1);
	buf2 = strdup(s2);
	for (int i = 0; i < (int)strlen(s1); i++)
	{
		if (buf1[i] == '#')
			buf1[i] = '\n';
		else if (buf1[i] == '@')
			buf1[i] = '\0';
	}
	for (int i = 0; i < (int)strlen(s2); i++)
	{
		if (buf2[i] == '#')
			buf2[i] = '\n';
		else if (buf2[i] == '@')
			buf2[i] = '\0';
	}
	printf("\033[1;37mTesting ft_strcmp: \"%s\" and \"%s\"\n", s1, s2);
	out[0] = ft_strcmp(buf1, buf2);
	out[1] = strcmp(buf1, buf2);
	printf("ft_strcmp: %i\n   strcmp: %i\n", out[0], out[1]);
	if (out[0] == out[1])
		printf("\033[1;32mMATCH\n");
	else
		printf("\033[1;31mNO MATCH\n");
	free(buf1);
	free(buf2);
	printf("\n");
}

static void	test_strdup(const char *str)
{
	char	*newstr;
	char	*buf1;
	char	*buf2;

	newstr = strdup(str);
	for (int i = 0; i < (int)strlen(str); i++)
	{
		if (newstr[i] == '#')
			newstr[i] = '\n';
		else if (newstr[i] == '@')
			newstr[i] = '\0';
	}
	printf("\033[1;37mTesting ft_strdup: Copying \"%s\"\n", str);
	buf1 = ft_strdup(newstr);
	buf2 = strdup(newstr);
	for (int i = 0; i < (int)strlen(buf1); i++)
	{
		if (buf1[i] == '\n')
			buf1[i] = '#';
	}
	for (int i = 0; i < (int)strlen(buf2); i++)
	{
		if (buf2[i] == '\n')
			buf2[i] = '#';
	}
	printf("ft_strdup: %s\n   strdup: %s\n", buf1, buf2);
	if (!strcmp(buf1, buf2))
		printf("\033[1;32mMATCH\n");
	else
		printf("\033[1;31mNO MATCH\n");
	free(newstr);
	free(buf1);
	free(buf2);
	printf("\n");
}

int			main(int ac, char **av)
{
	if (ac == 4 && !strcmp(av[1], "ft_write"))
		test_write(av[2], atoi(av[3]));
	else if (ac == 4 && !strcmp(av[1], "ft_read"))
		test_read(av[2], atoi(av[3]));
	else if (ac == 3 && !strcmp(av[1], "ft_strlen"))
		test_strlen(av[2]);
	else if (ac == 5 && !strcmp(av[1], "ft_strcpy"))
		test_strcpy(av[2], av[3], atoi(av[4]));
	else if (ac == 4 && !strcmp(av[1], "ft_strcmp"))
		test_strcmp(av[2], av[3]);
	else if (ac == 3 && !strcmp(av[1], "ft_strdup"))
		test_strdup(av[2]);
	else
	{
		printf("\033[1;31mInvalid arguments: ");
		for (int i = 0; i < ac; i++)
		{
			printf("%s ", av[i]);
		}
		printf("\n");
	}
	return (0);
}

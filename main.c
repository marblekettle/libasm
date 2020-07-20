/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmans <bmans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 10:06:18 by bmans         #+#    #+#                 */
/*   Updated: 2020/07/20 15:00:03 by bmans         ########   odam.nl         */
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
**	test_write: string to write | number of bytes to write
**	test_read: file to read from (stdin for stdin) | number of bytes to read
**	test_strlen: string to determine length of
**	test_strcpy: string to copy from | string to copy to | string size | offset
**	test_strcmp: string to compare | other string to compare
**	test_strdup; string to duplicate
**	note: character '@' is interpreted as a null character
*/

static void	test_write(const char *str, int nbytes)
{
	char	buf[30];
	int		fd[3];
	int		err[2];
	int		match;
	char	*tmpstr;

	tmpstr = strdup(str);
	for (int i = 0; i < nbytes; i++)
	{
		if (str[i] == '@')
			tmpstr[i] = '\0';
	}
	fd[0] = open("./1.txt", O_CREAT | O_RDWR, 0666);
	fd[1] = open("./2.txt", O_CREAT | O_RDWR, 0666);
	bzero(err, 8);
	bzero(buf, 30);
	printf("\033[1;37mTesting ft_write: %i bytes from \"%s\"\n", \
		nbytes, tmpstr);
	printf("ft_write: ");
	fflush(stdout);
	ft_write(1, tmpstr, nbytes);
	err[0] = errno;
	printf("\n   write: ");
	fflush(stdout);
	write(1, tmpstr, nbytes);
	err[1] = errno;
	printf("\n");
	ft_write(fd[0], tmpstr, nbytes);
	write(fd[1], tmpstr, nbytes);
	system("diff ./1.txt ./2.txt | wc -c > 3.txt");
	fd[2] = open("3.txt", O_RDWR);
	read(fd[2], buf, 30);
	match = atoi(buf);
	if (!match)
		printf("\033[1;32mMATCH\n");
	else
		printf("\033[1;31mNO MATCH\n");
	if (err[0] || err[1])
	{
		printf("\033[1;37mError codes:\nft_write: %i\n   write: %i\n", err[0], err[1]);
		if (err[0] == err[1])
			printf("\033[1;32mMATCH\n");
		else
			printf("\033[1;31mNO MATCH\n");
	}
	printf("\n");
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	system("rm ./1.txt && rm ./2.txt && rm ./3.txt");
	free(tmpstr);
}

int			main(int ac, char **av)
{
	if (ac == 4 && !strcmp(av[1], "ft_write"))
		test_write(av[2], atoi(av[3]));
//	else if (!strcmp(av[1], "ft_read") && ac == 4)
//		test_read(av[2], atoi(av[3]));
//	else if (!strcmp(av[1], "ft_strlen") && ac == 3)
//		test_strlen(av[2]);
//	else if (!strcmp(av[1], "ft_strcpy") && ac == 5)
//		test_strcpy(av[2], av[3], atoi(av[4]), atoi(av[5]));
//	else if (!strcmp(av[1], "ft_strcmp") && ac == 4)
//		test_strcmp(av[2], av[3]);
//	else if (!strcmp(av[1], "ft_strdup") && ac == 3)
//		test_strdup(av[2]);
	else
	{
		printf("Invalid arguments: ");
		for (int i = 0; i < ac; i++)
			printf("%s ", av[i]);
		printf("\n");
	}
	return (0);
}

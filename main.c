/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmans <bmans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 10:06:18 by bmans         #+#    #+#                 */
/*   Updated: 2020/07/20 11:04:43 by bmans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <string.h>

/*
**	test_write: string to write | number of bytes to write
**	test_read: file to read from (stdin for stdin) | number of bytes to read
**	test_strlen: string to determine length of
**	test_strcpy: string to copy from | string to copy to | string size | offset
**	test_strcmp: string to compare | other string to compare
**	test_strdup; string to duplicate
**	note: character '@' is interpreted as a null character
*/

int	main(int ac, char **av)
{
	int i;

	if (!strcmp(av[1], "ft_write") && ac == 4)
		test_write(av[2], atoi(av[3]));
	else if (!strcmp(av[1], "ft_read") && ac == 4)
		test_read(av[2], atoi(av[3]));
	else if (!strcmp(av[1], "ft_strlen") && ac == 3)
		test_strlen(av[2]);
	else if (!strcmp(av[1], "ft_strcpy") && ac == 5)
		test_strcpy(av[2], av[3], atoi(av[4]), atoi(av[5]));
	else if (!strcmp(av[1], "ft_strcmp") && ac == 4)
		test_strcmp(av[2], av[3]);
	else if (!strcmp(av[1], "ft_strdup") && ac == 3)
		test_strdup(av[2]);
	else
	{
		printf("Invalid arguments: ");
		i = 0;
		while (i < ac)
		{
			printf("%s ", av[i]);
			i++;
		}
		printf("\n");
	}
}

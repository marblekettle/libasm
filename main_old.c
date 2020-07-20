/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_old.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmans <bmans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 10:48:19 by bmans         #+#    #+#                 */
/*   Updated: 2020/07/20 12:15:40 by bmans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

extern int errno;

int	main(int ac, char **av)
{
//	char	buf[BUFFER_SIZE];
	char	*buf = malloc(100);
	char	dest[10];
	char	*ptr;
	char	*ptr2;
	int		cread;

/* 	printf("%zu %zu\n", ft_strlen("Hello\nHello\0Hello"), strlen("Hello\nHello\0Hello"));
	printf("%zu %zu\n", ft_strlen("\0\0\0"), strlen("\0\0\0"));
	ptr = ft_strcpy(dest, "cherry");
	ft_strcpy(ptr + 4, "apple");
	printf("%s %s\n", dest, ptr);
	ft_strcpy(ptr + 1, "");
	printf("%s %s\n", dest, ptr);
	ptr = strcpy(dest, "cherry");
	strcpy(ptr + 4, "apple");
	printf("%s %s\n", dest, ptr);
	strcpy(ptr + 1, ""); 
	printf("%s %s\n", dest, ptr);*/
	ptr = strcpy(dest, "che\0rry");
	printf("%s\n", ptr);
	ptr = ft_strdup("banana");
	ptr2 = strdup(ptr);
	printf("%s\n", ptr);
	free(ptr);
	/*printf("%i %i\n", ft_strcmp("apple", "apple"), strcmp("apple", "apple"));
	printf("%i %i\n", ft_strcmp("banana", "apple"), strcmp("banana", "apple"));
	printf("%i %i\n", ft_strcmp("apple", "applesauce"), strcmp("apple", "applesauce"));
	printf("%i %i\n", ft_strcmp("12345", "12367"), strcmp("12345", "12367")); */
	cread = ft_read(0, buf, 100);
	printf("%i %i\n", cread, errno);
	if (errno)
		perror("");
	//ft_write(1, buf, cread);
	//cread = read(0, buf, -1);
	//printf("%i %i\n", cread, errno);
	//if (errno)
	//	perror("");
	//ft_write(1, buf, cread);
	write(1, buf, cread);
/*	cread = ft_read(-1, buf, BUFFER_SIZE);
	printf("%i\n", cread);
	ft_write(1, buf, cread);
	cread = read(-1, buf, BUFFER_SIZE);
	write(1, buf, cread);
	cread = ft_read(0, buf, 0);
	ft_write(1, buf, cread);
	cread = read(0, buf, 0);
	write(1, buf, cread);
	cread = ft_read(0, buf, -1);
	ft_write(1, buf, cread);
	cread = read(0, buf, -1);
	write(1, buf, cread);
	cread = ft_read(0, NULL, BUFFER_SIZE);
	ft_write(1, NULL, cread);
	cread = read(0, NULL, BUFFER_SIZE);
	write(1, NULL, cread); */
	free(buf);
	return (0);
}

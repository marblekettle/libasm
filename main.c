/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmans <bmans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 10:48:19 by bmans         #+#    #+#                 */
/*   Updated: 2020/07/16 14:38:21 by bmans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(int ac, char **av)
{
	char	buf[BUFFER_SIZE];
	char	dest[10];
	char	*ptr;
	int		cread;

	printf("%zu %zu\n", ft_strlen("Hello\nHello\0Hello"), strlen("Hello\nHello\0Hello"));
	printf("%zu %zu\n", ft_strlen("\0\0\0"), strlen("\0\0\0"));
	ptr = ft_strcpy(dest, "cherry");
	ft_strcpy(ptr + 5, "apple");
	printf("%s %s\n", dest, ptr);
	ft_strcpy(ptr + 1, "");
	printf("%s %s\n", dest, ptr);
	ptr = strcpy(dest, "cherry");
	strcpy(ptr + 5, "apple");
	printf("%s %s\n", dest, ptr);
	strcpy(ptr + 1, "");
	printf("%s %s\n", dest, ptr);
	printf("%i %i\n", ft_strcmp("apple", "apple"), strcmp("apple", "apple"));
	printf("%i %i\n", ft_strcmp("banana", "apple"), strcmp("banana", "apple"));
	printf("%i %i\n", ft_strcmp("apple", "applesauce"), strcmp("apple", "applesauce"));
	printf("%i %i\n", ft_strcmp("12345", "12367"), strcmp("12345", "12367"));
	cread = ft_read(0, buf, BUFFER_SIZE);
	ft_write(1, buf, cread);
	cread = read(0, buf, BUFFER_SIZE);
	write(1, buf, cread);
	return (0);
}

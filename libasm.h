/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmans <bmans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 10:48:12 by bmans         #+#    #+#                 */
/*   Updated: 2020/07/16 11:23:20 by bmans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stdlib.h>

size_t	ft_write(int fildes, const void *buf, size_t nbyte);
size_t	ft_read(int fildes, void *buf, size_t nbyte);
size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bmans <bmans@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/14 10:48:12 by bmans         #+#    #+#                 */
/*   Updated: 2020/07/20 11:06:46 by bmans         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <stddef.h>

size_t	ft_write(int fildes, const void *buf, size_t nbyte);
size_t	ft_read(int fildes, void *buf, size_t nbyte);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *str);

#endif

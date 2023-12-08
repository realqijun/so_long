/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:59:28 by qang              #+#    #+#             */
/*   Updated: 2023/07/06 11:24:26 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define KUETIAU_SUP 10

char	*get_next_line(int fd);
char	*fusion(char *kuetiau, char *siu_pao);
void	throw_food_away(char **food, void (*yeet)(void *));
int		ft_strchr(char *str);
char	*get_rest_of_the_string(char *kuetiau);
char	*r_and_r(int fd, char **kuetiau, char *siu_pao, ssize_t readed);
void	dllm(char **kuetiau, char **siu_pao);

#endif

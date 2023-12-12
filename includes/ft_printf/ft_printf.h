/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:15:53 by qang              #+#    #+#             */
/*   Updated: 2023/05/16 15:18:22 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_flag
{
	int		justify;
	int		sign;
	int		base;
	int		space;
	int		pad;
	int		precision;
	size_t	width;
	size_t	prec;
}	t_flag;

void	s_putchar(int c, int *count);
void	s_putstr(char *str, int *count, t_flag *flags);
int		ft_printf(const char *s, ...);
void	s_putaddr(uintptr_t addy, int *count, t_flag *flags);
void	s_putnbr(int n, int *count, t_flag *flags);
void	s_putui(unsigned int n, int *count, t_flag *flags);
void	s_puthex(unsigned int n, int *count, t_flag *flags, int c);
void	ss_putchar(int c, int *count, t_flag *flags);
void	ft_puthex(unsigned int n, int *count, int c);
#endif

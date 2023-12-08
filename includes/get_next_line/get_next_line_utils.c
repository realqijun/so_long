/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:32:54 by qang              #+#    #+#             */
/*   Updated: 2023/07/05 18:33:24 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	throw_food_away(char **food, void (*yeet)(void *))
{
	yeet(*food);
	*food = NULL;
}

char	*fusion(char *kuetiau, char *siu_pao)
{
	char	*result;
	size_t	goreng;
	size_t	steam;

	goreng = 0;
	steam = 0;
	while (kuetiau[goreng])
		goreng++;
	while (siu_pao[steam])
		steam++;
	result = malloc(sizeof(char) * (goreng + steam + 1));
	if (!result)
		return (NULL);
	goreng = -1;
	steam = 0;
	while (kuetiau[++goreng])
		result[goreng] = kuetiau[goreng];
	while (siu_pao[steam])
		result[goreng++] = siu_pao[steam++];
	result[goreng] = 0;
	throw_food_away(&kuetiau, &free);
	return (result);
}

int	ft_strchr(char *str)
{
	while (*str)
	{
		if (*str == KUETIAU_SUP)
			return (1);
		str++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:00:18 by qang              #+#    #+#             */
/*   Updated: 2023/07/06 11:23:31 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest_of_the_string(char *kuetiau)
{
	size_t	dry;
	size_t	sup;
	char	*result;

	dry = 0;
	while (kuetiau[dry] != KUETIAU_SUP && kuetiau[dry])
		dry++;
	if (!kuetiau[dry])
	{
		throw_food_away(&kuetiau, &free);
		return (NULL);
	}
	sup = ++dry;
	while (kuetiau[dry])
		dry++;
	result = malloc(sizeof(char) * (dry - sup + 1));
	dry = 0;
	while (kuetiau[sup])
		result[dry++] = kuetiau[sup++];
	result[dry] = 0;
	throw_food_away(&kuetiau, &free);
	return (result);
}

void	dllm(char **kuetiau, char **siu_pao)
{
	int	sup;

	sup = 0;
	while ((*kuetiau)[sup] != KUETIAU_SUP && (*kuetiau)[sup])
		sup++;
	*siu_pao = malloc(sizeof(char) * (sup + 2));
	if (!*siu_pao)
		return ;
	sup = 0;
	while ((*kuetiau)[sup] != KUETIAU_SUP && (*kuetiau)[sup])
	{
		(*siu_pao)[sup] = (*kuetiau)[sup];
		sup++;
	}
	(*siu_pao)[sup] = (*kuetiau)[sup];
	(*siu_pao)[++sup] = 0;
}

char	*r_and_r(int fd, char **kuetiau, char *siu_pao, ssize_t readed)
{
	if (ft_strchr(*kuetiau) || readed == 0)
	{
		throw_food_away(&siu_pao, &free);
		if (!(**kuetiau))
		{
			throw_food_away(kuetiau, &free);
			return (NULL);
		}
		dllm(kuetiau, &siu_pao);
		*kuetiau = get_rest_of_the_string(*kuetiau);
		return (siu_pao);
	}
	else
	{
		readed = read(fd, siu_pao, BUFFER_SIZE);
		siu_pao[readed] = 0;
		*kuetiau = fusion(*kuetiau, siu_pao);
		return (r_and_r(fd, kuetiau, siu_pao, readed));
	}
}

char	*get_next_line(int fd)
{
	static char	*kuetiau;
	char		*siu_pao;

	if (BUFFER_SIZE == 0 || read(fd, NULL, 0))
		return (NULL);
	if (!kuetiau)
	{
		kuetiau = malloc(sizeof(char));
		if (!kuetiau)
			return (NULL);
		*kuetiau = 0;
	}
	siu_pao = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!siu_pao)
		return (NULL);
	return (r_and_r(fd, &kuetiau, siu_pao, 1));
}

// ＥＺ
// 　　　　　　 ／ ¯) 
// 　　　　　　／　／ 
// 　　　　　 ／　／ 
// 　　　／¯ ／　／'¯ ) 
// 　　／／ ／　／　／ ('＼ 
// 　（（ （　（　（　 ） ) 
// 　　＼　 NooB　 ＼／ ／ 
// 　　　＼　　　　　　／ 
// 　　　　＼ ＼

/* int	main(void)
 {
 	int	fd = open("b", O_RDONLY);

 	printf("%s", get_next_line(fd));
 	printf("%s", get_next_line(fd));
 }
*/

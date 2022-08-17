/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:53:51 by mochan            #+#    #+#             */
/*   Updated: 2022/08/17 12:16:41 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, int c)
{
	long int	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
	{
		if (*(str + i) == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *string1, char *string2)
{
	char		*str;
	long int	i;
	long int	j;

	if (!string1)
	{
		string1 = (char *)malloc(1 * sizeof(char));
		*(string1 + 0) = '\0';
	}
	if (!string1 || !string2)
		return (NULL);
	str = malloc(ft_strlen_gnl(string1) + ft_strlen_gnl(string2) + 1);
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (string1)
		while (*(string1 + ++i))
			*(str + i) = *(string1 + i);
	while (*(string2 + j))
		*(str + i++) = *(string2 + j++);
	*(str + i) = '\0';
	free(string1);
	return (str);
}

char	*new_string(char *string1)
{
	long int	i;
	long int	j;
	char		*str;

	i = 0;
	while (*(string1 + i) && *(string1 + i) != '\n')
		i++;
	if (!*(string1 + i))
	{
		free(string1);
		return (NULL);
	}
	str = malloc((ft_strlen_gnl(string1) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (*(string1 + i))
		*(str + j++) = *(string1 + i++);
	*(str + j) = '\0';
	free(string1);
	return (str);
}

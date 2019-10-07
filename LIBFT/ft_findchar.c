/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_findchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 16:59:53 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/08/08 16:59:55 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findchar(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

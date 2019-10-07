/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_findspace.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/09 10:51:24 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/08/09 10:51:26 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findspace(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (i);
	}
	return (-1);
}

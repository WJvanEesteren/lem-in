/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfndup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:49:19 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/08/22 17:49:21 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfndup(char *str, int n)
{
	char *res;
	int		i;

	res = ft_strnew(ft_strlen(str)); 
	i = 0;
	while (str[n])
	{
		res[i] = str[n];
		n++;
		i++;
	}
	return (res);
}

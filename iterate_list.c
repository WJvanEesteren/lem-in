/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterate_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 13:37:37 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/08/14 13:37:39 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_list(t_room **room)
{
	t_room *tmp;
	t_room *del;

	tmp = *room;
	del = *room;
	while (tmp)
	{
		free (tmp->name);
		tmp = tmp->next;
		del->next = tmp;
		free (del);
		del = del->next;
	}
}

void	iterate_list(t_room **room)
{
	t_room *tmp;

	tmp = *room;
	while (tmp)
	{
		ft_printf("room: %s ", tmp->name);
		ft_printf("pos: %i ", tmp->pos);
		ft_printf("ants: %i\n", tmp->ants);
		ft_printf("uid: %i\n", tmp->uid);
		tmp = tmp->next;
	}
}

void	show_hash_table(t_room **hash_table, t_lem *goods)
{
	int		y;
	t_room	*tmp;

	y = 0;
	tmp = hash_table[y];
	while (y < goods->rooms)
	{
		if (tmp)
		{
			ft_printf("hash table index = %i\n", y);
			ft_printf("room: %s \n", tmp->name);
			ft_printf("pos: %i \n", tmp->pos);
			ft_printf("ants: %i\n", tmp->ants);
			ft_printf("uid: %i\n", tmp->uid);
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
			{
				y++;
				tmp = hash_table[y];
			}
		}
		else
		{	
			y++;
			tmp = hash_table[y];
		}
	}
}


void	show_links_table(t_room **table, t_lem *goods)
{
	int		y;
	t_room	*tmp;

	y = 0;
	tmp = table[y];
	while (y < goods->rooms)
	{
		if (tmp)
		{
			ft_printf("par uid index = %i\n", y);
			ft_printf("kid name: %s\n", tmp->name);
			ft_printf("pos kid: %i\n", tmp->pos);
			ft_printf("ants: %i\n", tmp->ants);
			ft_printf("uid kid: %i\n", tmp->uid);
			if (tmp->next != NULL)
				tmp = tmp->next;
			else
			{
				y++;
				tmp = table[y];
			}
		}
		else
		{	
			y++;
			tmp = table[y];
		}
	}

}

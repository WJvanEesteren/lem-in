/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hash.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 13:38:16 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/08/14 13:38:17 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** Allocates memory for the hash table and sets each row to NULL
 */

static	t_room **create_table(int rooms)
{
	t_room **hash_table; 
	int		y;

	y = 0;
	hash_table = NULL;
	hash_table = (t_room**)malloc(sizeof(t_room*) * rooms + 1);
	if (hash_table == NULL)
		error("HASH TABLE MALLOC ERROR");
	while (y <= rooms)
	{
		hash_table[y] = NULL;
		y++;
	}
	return (hash_table);
}

/*
***  Sets the values in the hash table equal to the values in the relevant rooms
 */

static	void	add_room(t_room **hash_table, t_room *room, int hash)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (hash_table[hash] != NULL)
	{
		while (hash_table[hash]->next!= NULL)
			hash_table[hash] = hash_table[hash]->next;
		hash_table[hash]->next = new;
	}
	else
		hash_table[hash] = new;
	new->ants = room->ants;
	new->uid = room->uid;
	new->pos = room->pos;
	new->name = room->name;
	new->next = NULL;
}

/*
*** Hash function for creating the row index for the hash table which will store our rooms
 */

int		hash_func(char *name, int rooms)
{
	int			i;
	int			res;
	
	i = 0;
	res = 0;
	while (name[i])
	{
		res += name[i];
		i++;
	}
	return (res % rooms);
}

/*
*** Iterates through the already made linked list of rooms.
*** Makes a hash for each room based upon its name which will serve as its index in the table.
*** In the case of collision rooms will be stored in the same row.
 */

void	hash(t_lem *goods, t_room **room)
{
	t_room *tmp;

	tmp = *room;
	goods->hash_table = create_table(goods->rooms);
	while (tmp)
	{
		add_room(goods->hash_table, tmp, hash_func(tmp->name, goods->rooms));
		tmp = tmp->next;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linker.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 13:38:23 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/08/14 13:38:25 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
*** Allocates memory for array of links between rooms
 */

static	t_room **create_array(int rooms)
{
	t_room **link_table; 
	int		y;

	y = 0;
	link_table = NULL;
	link_table = (t_room**)malloc(sizeof(t_room*) * rooms + 1);
	if (link_table == NULL)
		error("LINK ARRAY MALLOC ERROR");
	while (y <= rooms)
	{
		link_table[y] = NULL;
		y++;
	}
	return (link_table);
}

/*
*** Adds the appropiate child room to neighbours tableß
 */

static	void	add_child(t_lem *goods, char *kid, t_room *new)
{
	int hash;
	t_room *tmp;

	hash = hash_func(kid, goods->rooms);
	tmp = goods->hash_table[hash];
	while (tmp->next && ft_strcmp(tmp->name, kid) != 0)
		tmp = tmp->next;
	new->uid = tmp->uid;
	new->name = ft_strdup(kid);
	if (new->uid == goods->end_uid)
		new->pos = 2;
	else
		new->pos = 1;
	new->ants = 0;
	new->next = NULL;
}

/*
*** Adds Adds each room to the array of linked lists using their "UID" as the row index for the array.
*** Connects rooms by setting the "next" pointer in each room to point to their link.
 */

static	void	add_rooms(t_lem *goods, int hash, char *par, char *kid)
{
	int		uid;
	t_room	*new;

	uid = 0;
	new = (t_room *)malloc(sizeof(t_room));
	while (goods->hash_table[hash] && ft_strcmp(par, goods->hash_table[hash]->name) != 0)
		goods->hash_table[hash] = goods->hash_table[hash]->next;
	uid = goods->hash_table[hash]->uid;
	if (goods->links[uid] != NULL)
	{
		while (goods->links[uid]->next != NULL)
			goods->links[uid] = goods->links[uid]->next;
		goods->links[uid]->next = new;
	}
	else 
		goods->links[uid] = new;
	add_child(goods, kid, new);
}

/*
 *** Make hash table and array of neighbours as you go 
 */
static	void	set_links(char *str, t_lem *goods)
{
	char	*par;
	char	*kid;

	if (goods->links == NULL)
		goods->links = create_array(goods->rooms);
	par = ft_strndup(str, ft_findchar(str, '-'));
	kid = ft_strfndup(str, ft_findchar(str, '-') + 1);
	add_rooms(goods, hash_func(par, goods->rooms), par, kid);
	free (kid);
	free (par);
}


/*
*** Goes through each string which includes linking info and makes the links
 */

void		linker(char *str, t_lem *goods, t_room **room)
{
	if (!*room)
		error("NO ROOMS");
	if (goods->start != 2 || goods->end != 2)
		error("NO START AND OR END GIVEN");
	if (goods->hash_table == NULL)
	{
		hash(goods, room);
		show_hash_table(goods->hash_table, goods);
		ft_printf("END OF HASH TABLE\n");
	}
	set_links(str, goods);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 13:37:56 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/08/14 13:37:57 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

/*
******************************************************************
*** error log:
1) try passing room without coordinates and no space at the end
******************************************************************
 */

/*
***	Assigns name to all rooms and changes position number for start and end rooms.
*** Also assigns all ants to start room
*** Saves the UID for the start room in the struct goods for later use.
 */

static	void		assign_info(char *str, t_lem *goods, t_room *tmp, int uid)
{
	if (str[0] >= '0' && str[0] <= '9') 
		tmp->name = ft_strndup(str, ft_findchar(str, ' '));
	else
		tmp->name = ft_strndup(str, ft_strlchr(str, ' ', ft_strlen(str)));
	if (goods->start == 1)
	{
		tmp->pos = 0;
		tmp->ants = goods->ants;
		goods->start_uid = uid;
	}
	else if (goods->end == 1)
	{
		tmp->pos = 2;
		goods->end_uid = uid;
	}
	else
		tmp->pos = 1;
}

/*
*** Allocated space for rooms as new links in a link list
*** and assigns a name and unique ID (UID) number too them.
 */

static	void		save_room(char *str, t_lem *goods, t_room **room)
{
	t_room *tmp;
	static int uid;

	if (*room == NULL)
	{
		*room = (t_room*)malloc(sizeof(t_room));
		tmp = *room;
	}
	else
	{
		tmp = *room;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (t_room*)malloc(sizeof(t_room));
		tmp = tmp->next;
		tmp->ants = 0;
		tmp->pos = 1;
	}
	assign_info(str, goods, tmp, uid);
	tmp->uid = uid;
	uid++;
	goods->rooms = uid;
	tmp->next = NULL;
}	

/*
*** Checks each line for input. Skips comments and errors on emtpy lines.
*** When input for a room is received it is stored as a new link in a linked list of rooms.
*** When input is found which determines the links between rooms the function "linker" is called.
 */

static	void		check_line(char *str, t_lem *goods, t_room **room)
{
	if (ft_strcmp(str, "") == 0)
		error("EMPTY LINE");
	if (goods->start == -1 && goods->ants == 0)
	{
		goods->ants = ft_atoi(str);
		if (goods->ants <= 0)
			error("NUMBER OF ANTS MUST BE GREATER THAN ZERO");
	}
	else if (ft_strcmp(str, "##start") == 0)
	{
		//ft_printf("%s\n", str);
		free (str);
		get_next_line(goods->fd, &str);
		goods->start = 1;
		save_room(str, goods, room);
		goods->start = 2;
	}
	else if (ft_strcmp(str, "##end") == 0)
	{
		//ft_printf("%s\n", str);
		free (str);
		get_next_line(goods->fd, &str);
		goods->end = 1;
		save_room(str, goods, room);
		goods->end = 2;
	}
	else if (str[0] == '#')
		return ;
	else if (ft_findchar(str, '-') >= 0)
		linker(str, goods, room);
	else
		save_room(str, goods, room);
}

int					main()
{
	char	*str;
	t_lem	goods;
	t_room *room;

	goods.start = -1;
	goods.end = -1;
	goods.ants = 0;
	goods.rooms = 0;
	goods.hash_table = NULL;
	goods.links = NULL;
	room = NULL;
	goods.fd = open("test.txt", O_RDONLY);
	while (get_next_line(goods.fd, &str))
	{
		check_line(str, &goods, &room);
		//ft_printf("%s\n", str);
		free(str);
	}
	//iterate_list(&room);
	//ft_printf("END OF LINKED LIST \n");
	show_links_table(goods.links, &goods);
	//ft_printf("The uid of start is %i\n", goods.start_uid);
	//path_finder(&goods);
	//ft_printf("Number of rooms is %i\n", goods.rooms);
	/*int		y;

	y = 0;
	while (y < goods.y)
	{
		ft_printf("%s\n", goods.links[y]);
		y++;
	}*/
	//free_list(&room); NOT NEEDED RIGHT NOW
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_finder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/26 11:45:25 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/08/26 11:45:27 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
***	Function which checks if a particular route leads to the end room
*** Returns 1 if it is valid.
 */

/*static	int		check_path(t_lem *goods, int uid)
{
	t_room *tmp;

	tmp = goods->links[uid];
	while (tmp)
	{
		if (tmp->pos == 2)
			return (1);
		uid = tmp->uid;
		//ft_printf("UID kid is: %i\n", uid);
		//if (tmp->next == NULL && tmp->pos == 1)

		//else 
			//tmp = goods->links[uid];
		//I want to check the kid uid & then go to that uid if I reach pos == 2
		// Then the path is valid
		// if (goods->links[uid]->next == NULL && goods->links[uid]->pos == 1)
	}
	return (0);
}*/

/*
***	Goes to the row in the neighbours table which has saved all of the neighbours of the starting room
*** Does this by using the UID saved in the struct "goods"
 */

void	path_finder(t_lem *goods)
{
	int		uid;
	
	/*uid = 0;
	while (uid <= goods->rooms && uid != goods->start_uid)
		uid++;
	//ft_printf("Neighbours index is %i", y);
	while (goods->links[uid])
		goods->links[uid] = goods->links[uid]->next;*/
	uid = goods->start_uid;
	//ft_printf("\n%i\n", check_path(goods, uid));
}
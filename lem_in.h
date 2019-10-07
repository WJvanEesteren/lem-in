/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-ees <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 13:37:47 by wvan-ees      #+#    #+#                 */
/*   Updated: 2019/08/14 13:37:50 by wvan-ees      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEM_IN_H
# define LEM_IN_H

# include "./LIBFT/libft.h"
# include <unistd.h>
# define BUFF_SIZE 4000
# define ENDL		'\n'

typedef	struct s_room
{
	char	*name;
	int		ants;
	int		pos;
	int		uid;
	struct s_room *next;
}				t_room;

typedef	struct s_lem
{
	int		start;
	int		end;
	int		ants;
	//fd can be removed at the end
	int		fd;
	int		rooms;
	int		start_uid;
	int		end_uid;
	t_room	**hash_table;
	t_room	**links;
}				t_lem;


int				get_next_line(const int fd, char **line);
int				hash_func(char *name, int rooms);
void			iterate_list(t_room **room);
void			free_list(t_room **room);
void			linker(char *str, t_lem *goods, t_room **room);
void			hash(t_lem *goods, t_room **room);
void			show_hash_table(t_room **hash_table, t_lem *goods);
void			show_links_table(t_room **table, t_lem *goods);
void			path_finder(t_lem *goods);
void			error(char *str);

# endif

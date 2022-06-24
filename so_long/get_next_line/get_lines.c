/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syule <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:17:43 by syule             #+#    #+#             */
/*   Updated: 2022/06/24 17:17:45 by syule            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../so_long.h"

void	free_prev(char **strs, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		free(strs[i]);
		++i;
	}
	free(strs);
}

char	**get_map_from_file(int fd, char *mapfile)
{
	int		size;
	int		check;
	char	**res;
	int		i;

	if (set_var_and_malloc(&size, &fd, &res, mapfile) < 0)
		return (0);
	i = -1;
	while (++i < size)
	{
		check = get_next_line(fd, &(res[i]));
		if (check < 0 || !res[i])
		{
			free_prev(res, i);
			print_error_and_exit("get_next_line error");
		}
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyolchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:43:46 by miyolchy          #+#    #+#             */
/*   Updated: 2024/09/15 21:43:48 by miyolchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char *argv[])
{
	int				n;
	struct s_walls	walls;

	if (argc != 2 || nums_count(argv[1]) % 4 != 0)
		return (error());
	n = nums_count(argv[1]) / 4;
	if (!valid(argv[1], n))
		return (error());
	walls.matrix = allocate_matrix(n);
	malloc_walls(&walls, n);
	fill_nums(&walls, argv, n);
	solve(&walls, 0, 0, n);
	if (walls.matrix[0][0] == 0)
		return (error());
	print_matrix(walls.matrix, n);
	free_walls(&walls);
	free_matrix(walls.matrix, n);
	return (0);
}

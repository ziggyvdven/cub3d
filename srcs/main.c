/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:51:12 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/11/02 14:50:51 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int32_t	main(int argc, char **argv)
{
	t_map_parse map_parse;

	if (argc != 2)
		ft_error_message(E_ARG);
	map_parse = ft_parsing(argv[1]);
	ft_free_ar(map_parse.map);
	ft_free_ar(map_parse.exec_map);
	return (0);
}

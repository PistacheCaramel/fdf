/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:21:33 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:21:36 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	checker(char *arg)
{
	int	i;

	i = ft_strlen(arg);
	if (i == 0)
		return (1);
	if (arg[i - 1] == 'f' && arg[i - 2] == 'd' && arg[i - 3] == 'f'
		&& arg[i - 4] == '.')
		return (0);
	return (1);
}
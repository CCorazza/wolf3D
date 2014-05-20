/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 08:03:30 by ccorazza          #+#    #+#             */
/*   Updated: 2014/05/18 09:43:29 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "wolf.h"

void		exit_gracefully(char *s)
{
	ft_putendl_fd("\033[31mError\033[0m", 2);
	ft_putstr("\t");
	ft_putendl_fd(s, 2);
	exit(1);
}

void		*ft_xmalloc(size_t size)
{
	void	*res;

	if ((res = (void*)malloc(size)) == NULL)
		exit_gracefully("No Memory Allocated. Exiting.");
	return (res);
}

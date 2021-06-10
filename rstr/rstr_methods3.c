/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_methods3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khafni <khafni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:32:37 by khafni            #+#    #+#             */
/*   Updated: 2021/06/10 14:36:28 by khafni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rstr.h"

int	is_str_at_rstr_end(t_rstr rs, char *str)
{
	int	e;
	int	i;
	int	j;

	e = 0;
	i = rs->len - 1;
	j = ft_strlen(str) - 1;
	while (j >= 0 && rstr_get(rs, i) != 42)
	{
		if (rstr_get(rs, i) != str[j])
			return (1);
		j--;
		i--;
	}
	return (0);
}

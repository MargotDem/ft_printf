/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:13:52 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/24 11:13:53 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_abs_ll(long long int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

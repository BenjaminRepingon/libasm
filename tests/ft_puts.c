/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:14:35 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/13 11:51:43 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfts.h>

int		main( int argc, char const *argv[] )
{
	if ( argc == 2 )
		ft_puts( argv[1] );
	ft_puts( 0 );
	return ( 0 );
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 10:19:15 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/13 13:54:27 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H
# include <string.h>

void	ft_bzero( void *s, size_t n );
char	*ft_strcat( char *s1, const char *s2 );
int		ft_isalpha( int c );
int		ft_isdigit( int c );
int		ft_isalnum( int c );
int		ft_isascii( int c );
int		ft_isprint( int c );
int		ft_toupper( int c );
int		ft_tolower( int c );
int		ft_puts( const char *s );
int		ft_strlen( const char *s );
void	*ft_memset( void *b, int c, size_t len );
void	*ft_memcpy( void *dst, const void *src, size_t n );
char	*ft_strdup( const char *s1 );
void	ft_cat( int fd );

char	*ft_strncat( char *s1, const char *s2, size_t n );
int		ft_isupper( int c );
int		ft_islower( int c );
void	*ft_strcpy( void *dst, const void *src );
void	*ft_strncpy( void *dst, const void *src, size_t n );

#endif

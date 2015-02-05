/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 13:26:01 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/05 17:39:38 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

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

void	print_mem( char *mem, int len )
{
	int i = 0;
	while( i < len )
	{
		printf( "[%d]", mem[i] );
		i++;
	}
	printf( "\n" );
}

int		main( void )
{
	// FT_BZERO
	write( 1, "--------\nTest ft_bzero: ", 24 );
	char	*test = strdup("abcdefghij");
	char	*test2 = strdup("abcdefghij");

	ft_bzero( test, 5 );
	bzero( test2, 5 );

	if ( memcmp( test, test2, 10 ) != 0 )
	{
		write( 1, "\n" , 1 );
		print_mem( test, 10 );
		print_mem( test2, 10 );
		write( 1, "\ntest1 result: " , 15 );
		write( 1, test , 10 );
		write( 1, ", expected result: " , 20 );
		write( 1, test2 , 10 );
		printf("\n\033[31mError\n\033[0m");
		exit( 0 );
	}

	test = test + 6;
	test2 = test2 + 6;

	ft_bzero( test, 3 );
	bzero( test2, 3 );

	test = test - 6;
	test2 = test2 - 6;

	if ( memcmp( test, test2, 10 ) != 0 )
	{
		print_mem( test, 10 );
		print_mem( test2, 10 );
		write( 1, "\ntest1 result: " , 16 );
		write( 1, test , 10 );
		write( 1, ", expected result: " , 20 );
		write( 1, test2 , 10 );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	free( test );
	free( test2 );
	printf("\033[32mOk\033[0m\n");



	// FT_STRCAT
	write( 1, "--------\nTest ft_strcat: ", 25 );
	char	*cat_test = strdup("abcde0000000");
	char	*cat_test2 = strdup("1234");
	char	*cat_test3 = strdup("abcde0000000");
	cat_test[5] = 0;
	cat_test3[5] = 0;

	ft_strcat( cat_test, cat_test2 );
	strcat( cat_test3, cat_test2 );

	if ( memcmp( cat_test, cat_test3, 10 ) != 0 )
	{
		write( 1, "\n" , 1 );
		print_mem( cat_test, 10 );
		print_mem( cat_test3, 10 );
		write( 1, "\ncat_test: " , 11 );
		write( 1, cat_test , 10 );
		write( 1, "\ncat_test2: " , 12 );
		write( 1, cat_test3 , 10 );
		write( 1, "\n" , 1 );
		printf("\nresult: %s, expected result: %s\n", cat_test, cat_test3 );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}

	char	buf[9];
	bzero( buf, 9 );

	ft_strcat( buf, "" );
	ft_strcat( buf, "Bon" );
	ft_strcat( buf, "j" );
	ft_strcat( buf, "our." );
	ft_strcat( buf, "" );
	if ( memcmp( buf, "Bonjour.", 8 ) != 0 )
	{
		printf("\nresult: %s, expected result: %s\n", buf, "Bonjour." );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	if ( buf != ft_strcat( buf, "" ) )
	{
		printf("\nresult: %d, expected result: %d\n", buf, ft_strcat( buf, "" ) );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	free( cat_test );
	free( cat_test2 );
	free( cat_test3 );
	printf("\033[32mOk\n\033[0m");



	int i = 0;
	int min = -42;
	int max = 200;
	// FT_ISALPHA
	printf( "--------\nTest ft_isalpha: " );
	for ( i = min; i < max; i++ )
	{
		if ( ft_isalpha( i ) != isalpha( i ) )
		{
			printf("\n[%d] -> result: %d, expected result: %d\n", i, ft_isalpha( i ), isalpha( i ) );
			printf("\033[31mError\n\033[0m");
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	// FT_ISDIGIT
	printf( "--------\nTest ft_isdigit: " );
	for ( i = min; i < max; i++ )
	{
		if ( ft_isdigit( i ) != isdigit( i ) )
		{
			printf("\n[%d] -> result: %d, expected result: %d\n", i, ft_isdigit( i ), isdigit( i ) );
			printf("\033[31mError\n\033[0m");
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	// FT_ISALNUM
	printf( "--------\nTest ft_isalnum: " );
	for ( i = min; i < max; i++ )
	{
		if ( ft_isalnum( i ) != isalnum( i ) )
		{
			printf("\n[%d] -> result: %d, expected result: %d\n", i, ft_isalnum( i ), isalnum( i ) );
			printf("\033[31mError\n\033[0m");
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	// FT_ISASCII
	printf( "--------\nTest ft_isascii: " );
	for ( i = min; i < max; i++ )
	{
		if ( ft_isascii( i ) != isascii( i ) )
		{
			printf("\n[%d] -> result: %d, expected result: %d\n", i, ft_isascii( i ), isascii( i ) );
			printf("\033[31mError\n\033[0m");
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	// FT_ISPRINT
	printf( "--------\nTest ft_isprint: " );
	for ( i = min; i < max; i++ )
	{
		if ( ft_isprint( i ) != isprint( i ) )
		{
			printf("\n[%d] -> result: %d, expected result: %d\n", i, ft_isprint( i ), isprint( i ) );
			printf("\033[31mError\n\033[0m");
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	// FT_TOUPPER
	printf( "--------\nTest ft_toupper: " );
	for ( i = min; i < max; i++ )
	{
		if ( ft_toupper( i ) != toupper( i ) )
		{
			printf("\n[%d] -> result: %d, expected result: %d\n", i, ft_toupper( i ), toupper( i ) );
			printf("\033[31mError\n\033[0m");
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	// FT_TOLOWER
	printf( "--------\nTest ft_tolower: " );
	for ( i = min; i < max; i++ )
	{
		if ( ft_tolower( i ) != tolower( i ) )
		{
			printf("\n[%d] -> result: %d, expected result: %d\n", i, ft_tolower( i ), tolower( i ) );
			printf("\033[31mError\n\033[0m");
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");


	// FT_PUTS
	printf( "--------\nTest ft_puts: \n" );
	int		a;
	int		b;
	if ( ( a = ft_puts( "ft_puts\n" ) ) != ( b = puts( "puts" ) ) )
	{
		printf("\nresult: %d, expected result: %d\n", a, b );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	if ( ( a = ft_puts( "" ) ) != ( b = puts( "" ) ) )
	{
		printf("\nresult: %d, expected result: %d\n", a, b );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	printf("\033[32mOk\n\033[0m");


	// FT_STRLEN
	printf( "--------\nTest ft_strlen: " );
	if ( ft_strlen( "chat" ) != strlen( "chat" ) )
	{
		printf("\n[%s] -> result: %d, expected result: %d\n", "chat", ft_strlen( "chat" ), strlen( "chat" ) );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	if ( ft_strlen( "" ) != strlen( "" ) )
	{
		printf("\n[%s] -> result: %d, expected result: %d\n", "", ft_strlen( "" ), strlen( "" ) );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	if ( ft_strlen( "abcde" ) != 5 )
	{
		printf("\n[%s] -> result: %d, expected result: %d\n", "abcde", ft_strlen( "abcde" ), 5 );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	printf("\033[32mOk\n\033[0m");


	// FT_MEMSET
	printf( "--------\nTest ft_memset: " );
	char		*test_memset1 = strdup( "abcdefghij" );
	char		*test_memset2 = strdup( "abcdefghij" );

	void	*ret1 = ft_memset( test_memset1, '1', 5 );
	void	*ret2 = memset( test_memset2, '1', 5 );

	if ( memcmp( test_memset1, test_memset2, 10 ) != 0 )
	{
		printf( "\nresult: \n" );
		print_mem( test_memset1, 10 );
		printf("\nexpected result: \n");
		print_mem( test_memset2, 10 );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	if ( memcmp( ret1, ret2, 10 ) != 0 )
	{
		printf( "\nresult: \n" );
		print_mem( ret1, 10 );
		printf("\nexpected result: \n");
		print_mem( ret2, 10 );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	free( test_memset1 );
	free( test_memset2 );
	printf("\033[32mOk\n\033[0m");


	// FT_MEMCPY
	printf( "--------\nTest ft_memcpy: " );
	char		*test_memcpy1 = strdup( "123456789" );
	char		*test_memcpy2 = strdup( "123456789" );

	char *retcpy1 = ft_memcpy( test_memcpy1, "abcdef", 5 );
	char *retcpy2 = memcpy( test_memcpy2, "abcdef", 5 );

	if ( memcmp( test_memcpy1, test_memcpy2, 10 ) != 0 )
	{
		printf( "\ntest1\nresult: \n" );
		print_mem( test_memcpy1, 10 );
		printf("\nexpected result: \n");
		print_mem( test_memcpy2, 10 );
		printf("%s\n", test_memcpy1);
		printf("%s\n", test_memcpy2);
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	if ( memcmp( retcpy1, retcpy2, 10 ) != 0 )
	{
		printf( "\ntest2\nresult: \n" );
		print_mem( retcpy1, 10 );
		printf("\nexpected result: \n");
		print_mem( retcpy2, 10 );
		printf("%s\n", retcpy1);
		printf("%s\n", retcpy2);
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}

	bzero( test_memcpy1, 10 );
	free( test_memcpy1 );
	bzero( test_memcpy2, 10 );
	free( test_memcpy2 );
	printf("\033[32mOk\n\033[0m");


	// FT_STRDUP
	printf( "--------\nTest ft_strdup: " );

	char	*test_dup1 = ft_strdup( "987654321" );
	char	*test_dup2 = strdup( "987654321" );

	if ( memcmp( test_dup1, test_dup2, 10 ) != 0 )
	{
		printf( "\nresult: \n" );
		print_mem( test_dup1, 10 );
		printf("\nexpected result: \n");
		print_mem( test_dup2, 10 );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}

	free( test_dup1 );
	free( test_dup2 );

	test_dup1 = ft_strdup( "9876\0pok" );
	test_dup2 = strdup( "9876\0pok" );

	if ( memcmp( test_dup1, test_dup2, 5 ) != 0 )
	{
		printf( "\nresult: \n" );
		print_mem( test_dup1, 5 );
		printf("\nexpected result: \n");
		print_mem( test_dup2, 5 );
		printf("\033[31mError\n\033[0m");
		exit( 0 );
	}
	printf("\033[32mOk\n\033[0m");

	return ( 0 );
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:19:15 by alfofern          #+#    #+#             */
/*   Updated: 2024/03/14 21:06:14 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a(4.42f);
	Fixed b(5);
	Fixed c(3.0f);
	Fixed d(3);
	Fixed abb = a + b + b;
	Fixed b_c = b - c;
	Fixed const	cb( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "------------------------" << std::endl;
	std::cout << "        My tests        "<< std::endl;
	std::cout << "------------------------" << std::endl;	
	std::cout << "valor de a: " << a << std::endl;
	std::cout << "valor de b: "<< b << std::endl;
	std::cout << "valor de c: "<< c << std::endl;
	std::cout << "valor de d: "<< d << std::endl;
	std::cout << "valor de a + b + b = " << abb << std::endl;
	std::cout << "valor de b - c = " << b_c << std::endl;
	std::cout << "valor de a * b = " << a * b << std::endl;
	std::cout << "valor de b / a = " << b / a << std::endl;
	
	if (b > c)
		std::cout << "b es mayor que c" << std::endl;
	if (a < b)
		std::cout << "a es menor que b" << std::endl;
	if (c >= d)
		std::cout << "c es mayor o igual que d" << std::endl;
	if (a <= b)
		std::cout << "a es menor o igual que b" << std::endl;
	if (d == c)
		std::cout << "d es igual que c" << std::endl;

	a.setRawBits(0);
	std::cout << "------------------------" << std::endl;
	std::cout << "    Subject sample      "<< std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << cb << std::endl;
	std::cout << Fixed::max( a, cb ) << std::endl;
	std::cout << "------------------------" << std::endl;

	return 0;
}

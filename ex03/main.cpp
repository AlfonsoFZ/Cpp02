/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:19:15 by alfofern          #+#    #+#             */
/*   Updated: 2024/03/16 00:24:58 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void checkPoint(Point const a, Point const b, Point const c, Point const point)
{
	std::cout << point << ": ";
	if (bsp(a, b, c, point))
		std::cout << "Dentro: bsp return true" <<std::endl;
	else
		std::cout << "Fuera: bsp return false" <<std::endl;
}

int main( void )
{

    Point a(-7.0f, -3.0f);
    Point b(3.0f, 8.0f);
    Point c(4.0f, -4.0f);
	
    Point d(0.0f, 0.0f);
    Point e(0.0f, 8.0f);
    Point f(4.0f, 4.0f);
	
	std::cout << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " triangle with negative value points " << std::endl;
    std::cout << "-------------------------------------" << std::endl << std::endl;
	std::cout << a << b << c << std::endl;
	
	Point point(0.0f, 0.0f);
    checkPoint(a, b, c, point);
    point = Point(-3.0f, 8.0f);
    checkPoint(a, b, c, point);
    point = Point(-8.0f, -3.0f);
    checkPoint(a, b, c, point);
	
	std::cout << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "        vertex and edge points       " << std::endl;
    std::cout << "-------------------------------------" << std::endl << std::endl;
	std::cout << d << e << f << std::endl;
    
	point = Point(0.0f, 0.0f);
    checkPoint(d, e, f, point);
	point = Point(0.0f, 2.0f);
	checkPoint(d, e, f, point);
	point = Point(0.5f, 2.0f);
	checkPoint(d, e, f, point);
	std::cout << "-------------------------------------" << std::endl << std::endl;
	
	return 0;
}

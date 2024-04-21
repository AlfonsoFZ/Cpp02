/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:06:49 by alfofern          #+#    #+#             */
/*   Updated: 2024/03/16 00:03:13 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/** Default Costrcutor:
 * @brief intialize the point values to 0
 */ 
Point::Point(): _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}
/** Const Float Constrcutor:
 */
Point::Point( const float fx, const float fy):_x(fx), _y(fy)
{
	// std::cout << "Float constructor called" << std::endl;
}
/** Copy Constructor:
 * @brief Construct a Point object with const Point object.
 * as values _x & _y are const we need to use const_cast to remove
 *  the "const" qualifier and be able to assign the values of the other object
 * @param other 
 */
Point::Point(const Point& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	const_cast<Fixed&>(this->_x) = other._x;
	const_cast<Fixed&>(this->_y) = other._y;
}

Fixed Point::getX( void ) const
{
	return (this->_x);
}

Fixed Point::getY( void ) const
{
	return (this->_y);
}

/** Destructor*/
Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}
/** ostream operator overload:
 * @brief takt an ostream and a Fixed object and returns the ostream 
 * with the value of the Fixed object converted to float 
 * 
 * @param os 
 * @param other 
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream &os, Point const &other )
{
	os <<  "(" << other.getX() << "," << other.getY() << ")";
	return os;
}

Point&	Point::operator=( const Point& other )
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		const_cast<Fixed&>(this->_x) = other._x;
		const_cast<Fixed&>(this->_y) = other._y;
	}
	return *this;
}

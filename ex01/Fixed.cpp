/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:06:49 by alfofern          #+#    #+#             */
/*   Updated: 2024/03/12 20:03:31 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/** Default Costrcutor:
 * @brief intialize the fixed point value to 0
 */ 
Fixed::Fixed(): _nbrValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
/** Const Float Constrcutor:
 * @brief Construct a new Fixed:: Fixed object with a floating point value
 * @param otherFloat 
 */
Fixed::Fixed( const float otherFloat )
{
	std::cout << "Float constructor called" << std::endl;
	this->_nbrValue = roundf(otherFloat * (1 << _bitPosition));
}

/** Const Int Constrcutor:
 * @brief Construct a new Fixed:: Fixed object with a fixed point value
 * to leave space for the fractional part we shift the integer value to the left
 * _bitPosition times.
 * @param otherInt 
 */
Fixed::Fixed( const int otherInt )
{
	std::cout << "Int constructor called" << std::endl;
	this->_nbrValue = otherInt << _bitPosition;
}

/** Copy Constructor:
 * @brief Construct a new Fixed:: Fixed object with a fixed point value
 * @param other 
 */
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/** Destructor
 * 
*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/** Assignment operator: 
 * return *This to allow chaining "a = b = c"
 * and avoid self-assignment, although it is not necessary in this case
 * because we are not using dynamic memory allocation.
 */
Fixed&	Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_nbrValue = other._nbrValue;
	return *this;
}

/** ostream operator overload:
 * @brief takt an ostream and a Fixed object and returns the ostream 
 * with the value of the Fixed object converted to float 
 * 
 * @param os 
 * @param other 
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream &os, Fixed const &other )
{
	os << other.toFloat();
	return os;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _nbrValue;
}
 
void Fixed::setRawBits(int const raw)
{
	this->_nbrValue = raw;
}

/** toFloat:
 * @brief convert a fixed point value to a floating point value
 * casting to float the result of the division of the fixed point value by 
 * 2 to the power of the number of fractional bits in this case 8 
 * (1 << this->_bitPosition)
 * @return float 
 */
float	Fixed::toFloat(void) const
{
	return static_cast<float>(static_cast<float>(this->_nbrValue) / (1 << this->_bitPosition));
}

/** toInt:
 * @brief to convert to int we simply move to the right the number of fractional bits
 * 
 * @return int 
 */
int		Fixed::toInt(void) const
{
	return (this->_nbrValue >> this->_bitPosition);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:07:07 by alfofern          #+#    #+#             */
/*   Updated: 2024/03/08 11:07:08 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructor initializes attributes to 0 by default 
Fixed::Fixed(): _nbrValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// in this case we can leave the Copy constructor as below
// because we are not using any dynamic memory allocation 
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Assignment operator: return *This to allow chaining "a = b = c"
// and avoid self-assignment, although it is not necessary in this case
// because we are not using dynamic memory allocation.
Fixed&	Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_nbrValue = other.getRawBits();
	return *this;
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
 
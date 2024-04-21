/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:06:58 by alfofern          #+#    #+#             */
/*   Updated: 2024/03/18 17:48:45 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>
#include <cmath>

/**
 * @brief rule of three: if you have to define one of them 
 *  you have to define all of them.
 * 	copy constructor, assignment operator and destructor
 */
class Fixed
{
	private: 
		int _nbrValue;
		static const int _bitPosition = 8;

	public:
		Fixed();
		Fixed( const float otherFloat );
		Fixed( const int otherInt );
		Fixed( const Fixed &other );
		~Fixed();
		Fixed& operator=( const Fixed &other );
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, Fixed const& other);


#endif

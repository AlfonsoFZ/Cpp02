/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:06:58 by alfofern          #+#    #+#             */
/*   Updated: 2024/03/14 20:29:36 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>
#include <cmath>

/**
 * @brief rule of three: ig you have to define one of them 
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
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
		
		// Marked as const to avoid modifying the object
		// this let`s use this overload with const  values
		bool operator>( const Fixed &other ) const; 
		bool operator<( const Fixed &other ) const;
		bool operator>=( const Fixed &other ) const;
		bool operator<=( const Fixed &other ) const;
		bool operator==( const Fixed &other ) const;
		bool operator!=( const Fixed &other ) const;

		Fixed&	operator=( const Fixed &other );
		Fixed	operator+( const Fixed &other ) const;
		Fixed	operator-( const Fixed &other ) const;
		Fixed	operator*( const Fixed &other ) const;
		Fixed	operator/( const Fixed &other ) const;
		
		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );
		
		static Fixed		&min( Fixed &a, Fixed &b );
		static const Fixed	&min( Fixed const &a, Fixed const &b);
		static Fixed& 			max( Fixed &a, Fixed &b );
		static const Fixed &    max( Fixed const & a, Fixed const & b);
		


};



std::ostream& operator<<(std::ostream& os, Fixed const& other);


#endif

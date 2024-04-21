/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:07:12 by alfofern          #+#    #+#             */
/*   Updated: 2024/03/12 18:48:55 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <string>
 
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
		Fixed( const Fixed &other);
		Fixed( const float & otherFloat );
		~Fixed();
		Fixed& operator=( const Fixed &other); 
		int getRawBits( void ) const;
		void setRawBits( int const raw );
}; 
 
#endif

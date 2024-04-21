/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:06:58 by alfofern          #+#    #+#             */
/*   Updated: 2024/03/15 23:14:28 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>
#include "Fixed.hpp"
#include <cmath>

/**
 * @brief rule of three: if you need to define one of them 
 *  you have to define all of them.
 * 	copy constructor, assignment operator and destructor
 */
class Point
{
	private: 
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point( const float fx, const float fy);
		Point( const Point &other );
		Point &operator=( const Point& other );
		Fixed getX( void ) const;
		Fixed getY( void ) const;
		~Point( void );
};

std::ostream& operator<<(std::ostream& os, Point const& other);

#endif

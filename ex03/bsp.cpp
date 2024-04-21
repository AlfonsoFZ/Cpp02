/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfofern <alfofern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 22:34:26 by alfofern          #+#    #+#             */
/*   Updated: 2024/03/16 00:26:06 by alfofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

/**
 * @brief determine if a point is inside a triangle
 * 	if conditions have been added to avoid division by zero.
 * 	formulas availables in the link below
 * @param a 
 * @param b 
 * @param c 
 * @param point 
 * @return true 
 * @return false 
 */
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point const	d((b.getX().toFloat() - a.getX().toFloat()),\
		 (b.getY().toFloat() - a.getY().toFloat()));
	Point const	e(c.getX().toFloat() - a.getX().toFloat(), \
		c.getY().toFloat() - a.getY().toFloat());
	Fixed w1, w2, zero;
	Fixed uno(1.0f);

	if (d.getX() * e.getY() - d.getY() * e.getX() == zero)
		w1 = (e.getX() * (a.getY() - point.getY()) + e.getY() * (point.getX() - a.getX())) / 0.002f;
	else
	{
		w1 = (e.getX() * (a.getY() - point.getY()) + e.getY() * (point.getX() - a.getX()))\
			/ (d.getX() * e.getY() - d.getY() * e.getX());
	}
	if (e.getY() == zero)
		w2 = (point.getY() - a.getY() - w1 * d.getY()) / 0.002f;
	else
		w2 = (point.getY() - a.getY() - w1 * d.getY()) / e.getY();

	if ( (w1 > zero) && (w2 > zero) && ((w1 + w2) < uno) )
		return true;
	else
		return false;
}
// https://es.quora.com/C%C3%B3mo-puedes-determinar-si-un-punto-dado-est%C3%A1-en-un-tri%C3%A1ngulo-dado

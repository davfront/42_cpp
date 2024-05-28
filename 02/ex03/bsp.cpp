/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:51:40 by dapereir          #+#    #+#             */
/*   Updated: 2023/05/24 15:33:29 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const p) {
	// Compute the vectors v0, v1, and v2
	Point	v0 = Point(c) - a;
	Point	v1 = Point(b) - a;
	Point	v2 = Point(p) - a;

	// Compute the dot products
	float	dot00 = Point::dot(v0, v0);
	float	dot01 = Point::dot(v0, v1);
	float	dot02 = Point::dot(v0, v2);
	float	dot11 = Point::dot(v1, v1);
	float	dot12 = Point::dot(v1, v2);

	// Compute the barycentric coordinates
    float	invDenom = 1.0f / (dot00 * dot11 - dot01 * dot01);
    float	u = (dot11 * dot02 - dot01 * dot12) * invDenom;
    float	v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	// Check if the point P is inside the triangle
    return ((u >= 0) && (v >= 0) && ((u + v - 1) <= 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:26:55 by galambey          #+#    #+#             */
/*   Updated: 2024/02/23 17:53:36 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

/*
Si un point M est à l’intérieur du triangle ABC, les angles AMB, BMC et CMA ont
	la même orientation, tandis que si le point M est à l’extérieur du triangle
	un des 3 angles à une orientation opposée.

*******************************************************************************
	La composante z d'un produit vectoriel, notée z​, est la troisième composante 
		du vecteur résultant du produit vectoriel de deux vecteurs dans un espace
		tridimensionnel.

	En mathématiques, le produit vectoriel de deux vecteurs A⃗
	et B⃗
	est un vecteur C⃗

	tel que:

	C⃗=A⃗×B⃗ ou C⃗=A⃗M×B⃗M

	Ce vecteur C⃗ est perpendiculaire au plan formé par A⃗ et B⃗
	, et sa longueur est proportionnelle à l'aire du parallélogramme formé par A⃗
	et B⃗.

	Dans un espace tridimensionnel, le produit vectoriel C⃗ a trois composantes cx​, cy​ et cz​,
	qui sont données par les formules suivantes:

	cx=AyBz−AzBy ou cx=(Ay - My)(Bz - Mz)−(Az - Mz)(By - My)
	cy=AzBx−AxBz ou cx=(Az - Mz)(Bx - Mx)−(Ax - Mx)(Bz - Mz)
	cz=AxBy−AyBx ou cx=(Ax - Mx)(By - My)−(Ay - My)(Bx - Mx)

	La composante z du produit vectoriel est donc calculée en prenant la différence entre
	les produits croisés des composantes x et y des deux vecteurs A⃗
	et B⃗.

	Cette composante z est souvent utilisée pour déterminer l'orientation relative des vecteurs
	dans un plan tridimensionnel, notamment lorsqu'on travaille avec des angles et des rotations
	dans l'espace.
*******************************************************************************

Donc pour savoir si les angles AMB, BMC et CMA ont la même orientation on va calculer
la composante z des plans  forme par A⃗M et B⃗M, B⃗M et C⃗M et C⃗M et A⃗M
 
*/
bool bsp( Point const a, Point const b, Point const c, Point const point) {
	
	short int i = Point::get_sign_comp_z(a, b, point);
	short int j = Point::get_sign_comp_z(b, c, point);
	short int k = Point::get_sign_comp_z(c, a, point);
	
	if ((i >= 0 && j >= 0 && k >= 0) || (i <= 0 && j <= 0 && k <= 0))
		return (1);
	return (0);
}

#pragma once

#include "tolerance_lib.h"
#include <iostream>

namespace Geometry
{

	/**
	 * Represents point in 3D space.
	 */
	class Point
	{
	public:
		Point(double x = 0.0, double y = 0.0, double z = 0.0);

		/**
		 * @return abscissa
		 */
		double x() const;

		/**
		 * @return ordinate
		 */
		double y() const;

		/**
		 * @return applique
		 */
		double z() const;

	private:
		double m_x = 0.0;
		double m_y = 0.0;
		double m_z = 0.0;
	};

	double distance(const Point& p1, const Point& p2);
	bool areEqual(const Point& p1, const Point& p2);

}

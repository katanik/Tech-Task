#include "point.h"

#include <cmath>

namespace Geometry
{

	Point::Point(double x, double y, double z) : m_x(x), m_y(y), m_z(z)
	{}

	double Point::x() const
	{
		return m_x;
	}

	double Point::y() const
	{
		return m_y;
	}

	double Point::z() const
	{
		return m_z;
	}

	double distance(const Point& p1, const Point& p2)
	{
		return sqrt((p1.x() - p2.x()) * (p1.x() - p2.x()) +
			(p1.y() - p2.y()) * (p1.y() - p2.y()) +
			(p1.z() - p2.z()) * (p1.z() - p2.z()));
	}

	bool areEqual(const Point& p1, const Point& p2)
	{
		return isEqual(p1.x(), p2.x()) && isEqual(p1.y(), p2.y()) && isEqual(p1.z(), p2.z());
	}

}

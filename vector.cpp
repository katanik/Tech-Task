#include "vector.h"

#include <cmath>

namespace Geometry
{

	Vector::Vector(double x, double y, double z) : m_x(x), m_y(y), m_z(z)
	{
	}

	double Vector::x() const
	{
		return m_x;
	}

	double Vector::y() const
	{
		return m_y;
	}

	double Vector::z() const
	{
		return m_z;
	}

	double Vector::length() const
	{
		return std::sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	}

	bool Vector::isDegenerate() const
	{
		return isZero(length());
	}

	Point Vector::toPoint() const
	{
		return Point{ m_x, m_y, m_z };
	}

	Vector toVector(const Point& p)
	{
		return Vector{ p.x(), p.y(), p.z() };
	}

	Vector operator*(const Vector& v, double db)
	{
		return Vector{ v.x() * db, v.y() * db , v.z() * db };
	}

	Vector operator*(double db, const Vector& v)
	{
		return v * db;
	}

	Vector operator/(const Vector& v, double db)
	{
		return Vector{ v.x() / db, v.y() / db , v.z() / db };
	}

	Vector crossProduct(const Vector& v1, const Vector& v2)
	{
		return Vector(v1.y() * v2.z() - v2.y() * v1.z(),
					  -v1.x() * v2.z() + v2.x() * v1.z(),
				      v1.x() * v2.y() - v2.x() * v1.y());
	}

	double dotProduct(const Vector& v1, const Vector& v2)
	{
		return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
	}

	Vector operator+(const Vector& v1, const Vector& v2)
	{
		return Vector{ v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z() };
	}

	Vector operator-(const Vector& v1, const Vector& v2)
	{
		return Vector{ v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z() };
	}

}

#pragma once
#include "point.h"

namespace Geometry
{

	/**
	 * Represents vector in 3D space.
	 */
	class Vector
	{
	public:
		Vector(double x, double y, double z);

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

		/**
		 * Point representation of vector
		 * @return point
		 */
		Point toPoint() const;

		/**
		 * @return the vector length
		 */
		double length() const;

		/**
		 * @return true if the vector is degenerate
		 */
		bool isDegenerate() const;

	private:
		double m_x, m_y, m_z;
	};

	/**
	 * Creates radius vector for the point
	 * @return vector
	 */
	Vector toVector(const Point& p);
 
	/**
	 * Multiplies the vector by a scalar
	 * @return result vector
	 */
	Vector operator*(const Vector& v, double db);
	Vector operator*(double db, const Vector& v);

	/**
	 * Divides the vector by a scalar
	 * @return result vector
	 */
	Vector operator/(const Vector& v, double db);

	/**
	 * Calculates the vector resulting from the addition of the two vectors
	 * @return result vector
	 */
	Vector operator+(const Vector& v1, const Vector& v2);

	/**
	 * Calculates the vector resulting from the addition of v1 and the vector opposite to v2
	 * @return result vector
	 */
	Vector operator-(const Vector& v1, const Vector& v2);

	/**
	 * Calculates the cross product of two vectors
	 * @return result vector
	 */
	Vector crossProduct(const Vector& v1, const Vector& v2);

	/**
	 * Calculates the dot product of two vectors
	 * @return result scalar
	 */
	double dotProduct(const Vector& v1, const Vector& v2);

}

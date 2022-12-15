#pragma once

#include "vector.h"

namespace Geometry
{

	/**
	 * Represents segment in 3D space.
	 */
	class Segment
	{
	public:
		Segment(const Point& p1, const Point& p2);

		/**
		 * @return true if the segment id degenerate
		 */
		bool isDegenerate() const;

		/**
		 * @return segment length
		 */
		double length() const;

		/**
		 * @return segment start point
		 */
		Point startPoint() const;

		/**
		 * @return segment end point
		 */
		Point endPoint() const;

		/**
		 * @return direction vector of the segment
		 */
		Vector directionVector() const;

		/**
		 * @return the nearest point on the segment to the target point
		 */
		Point getNearestPoint(const Point& targetPoint) const;

	private:
		Point m_startPoint, m_endPoint;
	};

}

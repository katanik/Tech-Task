#include "segment.h"

namespace Geometry
{

	Segment::Segment(const Point& p1, const Point& p2)
		: m_startPoint(p1), m_endPoint(p2)
	{}

	bool Segment::isDegenerate() const
	{
		return length() < s_tolerance;
	}

	double Segment::length() const
	{
		return distance(m_startPoint, m_endPoint);
	}

	Point Segment::startPoint() const
	{
		return m_startPoint;
	}

	Point Segment::endPoint() const
	{
		return m_endPoint;
	}

	Vector Segment::directionVector() const
	{
		return toVector(m_endPoint) - toVector(m_startPoint);
	}

	Point Segment::getNearestPoint(const Point& targetPoint) const
	{
		const auto dirVector = directionVector();
		const auto targetRadiusVector = toVector(targetPoint);
		const auto startRadiusVector = toVector(m_startPoint);

		// Special parameter which sets segment on the line, belongs to [0, 1].
		const double segmentParameter =
			dotProduct((targetRadiusVector - startRadiusVector), dirVector) /
			dotProduct(dirVector, dirVector);

		// In the cases below, check the ends of the segment
		if (isLessOrEqual(segmentParameter, 0.0))
			return m_startPoint;

		if (isGreaterOrEqual(segmentParameter, 1.0))
			return m_endPoint;

		// General case if the projection point belongs to the segment
		return (startRadiusVector + (dirVector * segmentParameter)).toPoint();
	}

}

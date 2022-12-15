#include "polyline.h"

#include <limits>

namespace Geometry
{

	ProjectionPointData::ProjectionPointData(const Point& p, unsigned segmentId)
		: m_point(p), m_aSegmentsIds(1, segmentId)
	{}

	Point ProjectionPointData::point() const
	{
		return m_point;
	}

	const std::vector<unsigned>& ProjectionPointData::segmentIds() const
	{
		return m_aSegmentsIds;
	}

	void ProjectionPointData::addSegment(unsigned segmentId)
	{
		m_aSegmentsIds.push_back(segmentId);
	}

	void Polyline::appendPoint(const Point& point)
	{
		m_aPoints.push_back(point);
	}

	std::vector<ProjectionPointData> Polyline::findNearestPoints(const Point& targetPoint)
	{
		auto minDistance = std::numeric_limits<double>::max();

		std::vector<ProjectionPointData> aProjectionPoints;

		// Returns true if there is already the same point (with tolerance)
		auto checkPointCoincidence = [&aProjectionPoints](const Point& curPoint, unsigned newSegmentIndex)
		{
			for (auto& projectionData : aProjectionPoints)
			{
				// It assumed that there is one such an object for the same point in aProjectionPoints 
				if (areEqual(projectionData.point(), curPoint))
				{
					projectionData.addSegment(newSegmentIndex);
					return true;
				}
			}

			return false;
		};

		for (size_t idx = 0; idx < m_aPoints.size() - 1; ++idx)
		{
			const Segment curSegment{ m_aPoints[idx], m_aPoints[idx + 1] };
			Point curPoint = curSegment.getNearestPoint(targetPoint);
			double curDistance = distance(targetPoint, curPoint);
			if (isLess(curDistance, minDistance))
			{
				minDistance = curDistance;

				// In this case just update the list of points
				aProjectionPoints.clear();
				aProjectionPoints.push_back(ProjectionPointData{ curPoint, idx + 1 });
			}
			else if (isEqual(curDistance, minDistance))
			{
				// If there was the same point before, update the list of its segments
				if (!checkPointCoincidence(curPoint, idx + 1))
					aProjectionPoints.push_back(ProjectionPointData{ curPoint, idx + 1 });
			}
		}

		return aProjectionPoints;
	}

}

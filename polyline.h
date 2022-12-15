#pragma once

#include "segment.h"

#include <vector>

namespace Geometry
{

	/**
	 * Auxiliary class which stores necessary data of a projection point on segment.
	 */
	class ProjectionPointData
	{
	public:
		/**
		 * Creates projection point data by the point and an id of the segment on which it lies.
		 */
		ProjectionPointData(const Point& p, unsigned segmentId);

		/**
		 * @return point
		 */
		Point point() const;

		/**
	     * Returns all ids of segments which contain the point.
		 * @return segment ids vector
		 */
		const std::vector<unsigned>& segmentIds() const;

		/**
	     * Adds a new id of the segment containing the point
		 * @param segmentId
		 */
		void addSegment(unsigned segmentId);

	private:
		Point m_point;
		std::vector<unsigned> m_aSegmentsIds;
	};

	/**
	 * Represents point in 3D space
	 */
	class Polyline
	{
	public:
		Polyline() = default;

		/**
		 * Appends a new point for the polyline
		 */
		void appendPoint(const Point& point);

		/**
		 * Finds all nearest points on the polyline to the target point and writes them to the output stream.
		 * The main idea is to check all segments of the polyline one by one.
		 * Stores all the segments ids for minimum distance between the current segment and the target point.
		 * @param targetPoint - the point for which we are looking for the nearest ones
		 * @returns projection points with all segments ids on which they lie.
		 */
		std::vector<ProjectionPointData> findNearestPoints(const Point& targetPoint);

	private:
		std::vector<Point> m_aPoints;
	};

}

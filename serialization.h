#pragma once

#include "polyline.h"

namespace Serialization
{
	/**
	 * Provides utilities to read geometry object. 
	 */
	class GeometryReader
	{
	public:
		/**
		 * Reads point coordinates from the input stream.
		 * @param inStream - input stream
		 * @return point objects with read coordinates
		 */
		static Geometry::Point readPoint(std::istream& inStream);

		/**
		 * Reads polyline points from the input stream.
		 * @param inStream - input stream
		 * @return polyline built with read points
		 */
		static Geometry::Polyline readPolyline(std::istream& inStream);
	};

	/**
	 * Provides utilities to write geometry object.
	 */
	class GeometryWriter
	{
	public:
		/**
		 * Writes point coordinates to the output stream.
		 * @param outStream - output stream
		 * @param point which coordinates need to be written
		 */
		static void writePoint(std::ostream& outStream, const Geometry::Point& point);

		/**
		 * Writes projection point and all ids of segments on which it lies in required format.
		 * @param outStream - output stream
		 * @param pointData - data of projection point which consists of point itself and segments ids
		 */
		static void writeProjectionPoint(std::ostream& outStream, const Geometry::ProjectionPointData& pointData);
	};

}

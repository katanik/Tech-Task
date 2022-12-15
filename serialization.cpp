#include "serialization.h"

namespace Serialization
{

	Geometry::Point GeometryReader::readPoint(std::istream& inStream)
	{
		double x, y, z;
		inStream >> x >> y >> z;
		return Geometry::Point{ x, y, z };
	}

	Geometry::Polyline GeometryReader::readPolyline(std::istream& inStream)
	{
		Geometry::Polyline polyline{};
		double x, y, z;
		while (inStream >> x >> y >> z)
		{
			polyline.appendPoint(Geometry::Point{ x, y, z });
		}

		return polyline;
	}

	void GeometryWriter::writePoint(std::ostream& outStream, const Geometry::Point& point)
	{
		outStream << point.x() << " " << point.y() << " " << point.z();
	}

	void GeometryWriter::writeProjectionPoint(std::ostream& outStream, const Geometry::ProjectionPointData& pointData)
	{
		auto writeSegment = [&outStream, &pointData](unsigned curId)
		{
			outStream << "segment " << curId << " point ";
			writePoint(outStream, pointData.point());
		};

		std::vector<unsigned> aSegmentIds = pointData.segmentIds();
		if (aSegmentIds.empty())
			return;

		writeSegment(aSegmentIds[0]);
		for (size_t idx = 1; idx < aSegmentIds.size(); idx++)
		{
			outStream << "\nor\n";
			writeSegment(aSegmentIds[idx]);
		}

		outStream << "\n";
	}

}

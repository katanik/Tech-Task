#include <iostream>
#include <fstream>
#include <string>

#include "polyline.h"
#include "serialization.h"

// The general function of this solution which reads polyline points from file and out 
bool runProjectionPointsSearch(std::istream& nodesStream, std::istream& targetPointStream, std::ostream& outStream)
{
    auto polyline = Serialization::GeometryReader::readPolyline(nodesStream);
    auto targetPoint = Serialization::GeometryReader::readPoint(targetPointStream);

    auto projectionPoints = polyline.findNearestPoints(targetPoint);
    for (const auto& pointData : projectionPoints)
    {
        Serialization::GeometryWriter::writeProjectionPoint(outStream, pointData);
    }

    return true;
}

namespace Testing
{
    std::string pathPrefix()
    {
        static std::string pathPref{ "E:\\test_tasks\\Tech-Task" };
        return pathPref;
    }

    void runSolution(unsigned fileIndex)
    {
        std::ifstream nodesStream{ pathPrefix() + "\\tests\\nodes_" + std::to_string(fileIndex) + ".txt" };
        std::ifstream targetPointStream{ pathPrefix() + "\\tests\\target_point_" + std::to_string(fileIndex) + ".txt" };
        std::ofstream outputStream{ pathPrefix() + "\\outputs\\output_" + std::to_string(fileIndex) + ".txt" };

        if (nodesStream.is_open() && targetPointStream.is_open() && outputStream.is_open())
        {
            outputStream.flush();
            runProjectionPointsSearch(nodesStream, targetPointStream, outputStream);
        }

        nodesStream.close();
        targetPointStream.close();
        outputStream.close();
    }

    void runTesting()
    {
        runSolution(1); // sample test 1
        runSolution(2); // sample test 2
		runSolution(3); // sample test 3
		runSolution(4); // test when the target point equidistant from all segments
		runSolution(5); // test when the target point lies on a segment
		runSolution(6); // test when the target point is a polyline node
		runSolution(7); // test with degenerate polyline (just a point)
		runSolution(8); // test with overlapping segments
		runSolution(9); // test where point is segments intersection
		runSolution(10); // test with the one nearest point on the different segments
    }
}

int main()
{
	std::string fileName;
	std::cin >> fileName;

	try
	{
		std::ifstream inStream{ fileName };
		if (inStream.is_open())
		{
			runProjectionPointsSearch(inStream, std::cin, std::cout);
		}

		inStream.close();

	}
	catch (const std::exception& ex)
	{
		std::cerr << "Error:\n" << ex.what();
	}

    //Testing::runTesting();
}

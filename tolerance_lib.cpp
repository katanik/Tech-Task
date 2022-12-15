#include "tolerance_lib.h"

#include <cmath>

bool isEqual(double db1, double db2)
{
	return std::fabs(db1 - db2) <= s_tolerance;
}

bool isZero(double db)
{
	return std::fabs(db) <= s_tolerance;;
}

bool isLessOrEqual(double db1, double db2)
{
	return db1 <= db2 + s_tolerance;
}

bool isGreaterOrEqual(double db1, double db2)
{
	return db1 >= db2 - s_tolerance;
}

bool isLess(double db1, double db2)
{
	return db1 < db2 - s_tolerance;
}

#pragma once

const double s_tolerance = 1e-9;

/**
 * Utility functions for correct comparison with tolerance
 */

bool isEqual(double db1, double db2);
bool isZero(double db);
bool isLessOrEqual(double db1, double db2);
bool isGreaterOrEqual(double db1, double db2);
bool isLess(double db1, double db2);

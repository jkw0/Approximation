#pragma once
#include <map>

using Point = std::pair<double, double>;
using Points = std::map<double, double>;
using Range = std::pair<double, double>;

class PointsGenerator
{
    Range range;
    double generateRandomNumber();
    Point generateOnePoint();
public:
    PointsGenerator(double min, double max);
    Points generatePoints(uint numberOfPoints);
    void setRange(double min, double max);
};
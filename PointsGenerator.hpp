#pragma once
#include <map>

using Point = std::pair<double, double>;
using Points = std::map<double, double>;
using Range = std::pair<double, double>;

class PointsGenerator
{
    Range rangeX;
    Range rangeY;
    double generateRandomNumber(Range range);
    Point generateOnePoint();

public:
    PointsGenerator(double minX, double maxX, double minY, double maxY);
    Points generatePoints(uint numberOfPoints);
    void setRange(double minX, double maxX, double minY, double maxY);
    Range getRangeX() const;
    Range getRangeY() const;
};
#pragma once
#include <map>

using Point = std::pair<double, double>;
using Points = std::map<double, double>;

class PointsGenerator
{
    struct Settings
    {
        double minX, step;
        double minY, maxY;
    } settings;
    
    double generateRandomNumber(double min, double max);
    Point generateOnePoint();

public:
    PointsGenerator(Settings settings_);
    Points generatePoints(uint numberOfPoints);
    void setNewSettings(Settings settings_);
};
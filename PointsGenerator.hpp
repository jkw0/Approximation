#pragma once
#include <map>

using Point = std::pair<double, double>;
using Points = std::map<double, double>;
class PointsGenerator
{
    double generateRandomNumber(double min, double max);

public:
    Points generateDataset(double min, double max, double step, double coefA = 2, double coefB = -0.2, double coefRandom = 0.1);
};
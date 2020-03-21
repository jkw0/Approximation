#pragma once
#include <map>
#include <vector>

using Point = std::pair<double, double>;
using Points = std::map<double, double>;
class PointsGenerator
{
    static constexpr double minRandom = 0;
    static constexpr double maxRandom = 5;

    double generateRandomNumber(double min, double max);

public:
    Points generateDataset(double min = 0, double max = 5, double step = 0.2,
                            double coeffA = 2, double coeffB = -0.2, double coeffRandom = 0.1);
};
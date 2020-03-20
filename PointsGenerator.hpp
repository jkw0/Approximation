#pragma once
#include <map>
#include <vector>

using Point = std::pair<double, double>;
using Points = std::map<double, double>;
using AxisX = std::vector<double>;
using AxisY = std::vector<double>;

class PointsGenerator
{
    struct Settings
    {
        double minX, step;
        double minY, maxY;
    } settings;
    
    double generateRandomNumber(double min, double max);
    Point generateOnePoint();

    AxisX generateAxisX(double min, double max, double step);
    AxisX generateAxisX(double min, uint32_t numOfPoints, double step);
    AxisY generateAxisY(AxisX axisX, double coeffA, double coeffB, double coeffRandom);

public:
    PointsGenerator(Settings settings_);
    Points generatePoints(uint numberOfPoints);
    void setNewSettings(Settings settings_);
    Points generateDataset(double min, double max, double step, double coeffA = 2, double coeffB = -0.2, double coeffRandom = 0.1 );
    Points generateDataset(double min, double step, uint32_t numOfPoints, double coeffA = 2, double coeffB = -0.2, double coeffRandom = 0.1 );
};
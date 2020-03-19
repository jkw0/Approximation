#include "PointsGenerator.hpp"
#include <random>

PointsGenerator::PointsGenerator(double minX, double maxX, double minY, double maxY)
    : rangeX(minX, maxX), rangeY(minY, maxY)
{
}

Points PointsGenerator::generatePoints(uint numberOfPoints)
{
    Points points;
    for (auto i = 0; i < numberOfPoints; i++)
        points.insert(generateOnePoint());

    return points;
}

void PointsGenerator::setRange(double minX, double maxX, double minY, double maxY)
{
    rangeX.first = minX;
    rangeX.second = maxX;
    rangeY.first = minY;
    rangeY.second = maxY;
}

/****************************/

double PointsGenerator::generateRandomNumber(Range range)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(range.first, range.second);

    return dis(gen);
}

Point PointsGenerator::generateOnePoint()
{
    double x = generateRandomNumber(rangeX);
    double y = generateRandomNumber(rangeY);

    return Point(x,y);
}
#include "PointsGenerator.hpp"
#include <random>

PointsGenerator::PointsGenerator(double min, double max) : range(min, max)
{
}

Points PointsGenerator::generatePoints(uint numberOfPoints)
{
    Points points;
    for (auto i = 0; i < numberOfPoints; i++)
        points.insert(generateOnePoint());
}

void PointsGenerator::setRange(double min, double max)
{
    range.first = min;
    range.second = max;
}

/****************************/

double PointsGenerator::generateRandomNumber()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(range.first, range.second);

    return dis(gen);
}

Point PointsGenerator::generateOnePoint()
{
    double x = generateRandomNumber();
    double y = generateRandomNumber();

    return Point(x,y);
}
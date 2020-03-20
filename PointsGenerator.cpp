#include "PointsGenerator.hpp"
#include <random>
#include <iostream>

PointsGenerator::PointsGenerator(PointsGenerator::Settings settings_)
    : settings(settings_)
{
}

Points PointsGenerator::generatePoints(uint numberOfPoints)
{
    Points points;
    for (auto i = 0; i < numberOfPoints; i++)
        points.insert(generateOnePoint());

    return points;
}

void PointsGenerator::setNewSettings(PointsGenerator::Settings settings_)
{
    settings = settings_;
}

/****************************/

double PointsGenerator::generateRandomNumber(double min, double max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(min, max);

    return dis(gen);
}

Point PointsGenerator::generateOnePoint()
{
    static double valueX = settings.minX;
    double x = valueX;
    valueX += 0.5;

    double y = generateRandomNumber(settings.minY, settings.maxY) * exp;

    std::cout << x << " " << y << std::endl;

    return Point(x,y);
}
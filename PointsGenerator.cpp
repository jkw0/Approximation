#include "PointsGenerator.hpp"
#include <random>
#include <iostream>

Points PointsGenerator::generateDataset(double min, double max, double step, double coefA, double coefB, double coefRandom)
{
    Points points{};

    for(double x = min; x <= max ; x += step )
    {
        double y = coefA*exp(coefB*x) + coefRandom*generateRandomNumber(min, max);
        std::cout << x << " " << y << std::endl;
        points.insert({x,y});
    }

    return points;
}
/****************************/

double PointsGenerator::generateRandomNumber(double min, double max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(min, max);

    return dis(gen);
}
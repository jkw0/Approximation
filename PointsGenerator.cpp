#include "PointsGenerator.hpp"
#include <random>
#include <iostream>

Points PointsGenerator::generateDataset(double min, double max, double step, double coeffA, double coeffB, double coeffRandom)
{
    Points points{};

    for(double x = min; x <= max ; x += step )
    {
        double y = coeffA*exp(coeffB*x) + coeffRandom*generateRandomNumber(minRandom, maxRandom);
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
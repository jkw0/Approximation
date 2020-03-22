#include "Approximation.hpp"
#include <cmath>
#include <iostream>

Approximation::Approximation(double minX, double maxX, double step)
    : generator()
{
    points = generator.generateDataset(minX, maxX, step, 2, -0.2, 0.1);
    numberOfPoints = points.size();
}

void Approximation::printCoefficients() const
{
    std::cout << "a = " << a.at(0) << " b = " << b.at(0) << std::endl;;
}

void Approximation::calculate()
{
    double z = 0, sumXi = 0, sumZi = 0, sumXiZi = 0, sumXiSq = 0;
    for(auto pts : points)
    {
        z = log(pts.second);
        sumXi += pts.first;
        sumZi += z;
        sumXiZi += pts.first * z;
        sumXiSq += pts.first * pts.first;
    }

    double a1 = 0, a0 = 0;
    a1 = (numberOfPoints*sumXiZi - sumXi*sumZi) / (numberOfPoints*sumXiSq - sumXi*sumXi);
    a0 = sumZi/numberOfPoints - a1*sumXi/numberOfPoints;

    a.push_back(exp(a0));
    b.push_back(a1);
}
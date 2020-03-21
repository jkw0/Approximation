#include "Approximation.hpp"
#include <cmath>
#include <iostream>

Approximation::Approximation(double minX, double maxX, double step)
    : generator()
{
    points = generator.generateDataset(minX, maxX, step, 2, -0.2, 0.01);
    numberOfPoints = points.size();
}

double Approximation::getA() const
{
    return a;
}

double Approximation::getB() const
{
    return b;
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

    a = exp(a0);
    b = a1;
}
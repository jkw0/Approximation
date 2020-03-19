#include "Approximation.hpp"
#include <cmath>

Approximation::Approximation(double minX, double maxX, double minY, double maxY, uint numberOfPoints)
    : generator(minX, maxX, minY, maxY)
{
    points = generator.generatePoints(numberOfPoints);
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
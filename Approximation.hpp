#pragma once
#include "PointsGenerator.hpp"
#include <vector>

using Coefficients = std::vector<double>;
class Approximation
{
    Coefficients a, b;
    Points points;
    PointsGenerator generator;
    uint numberOfPoints;

public:
    Approximation(double minX, double maxX, double step);
    void calculate();
    void printCoefficients() const;
};
#pragma once
#include "PointsGenerator.hpp"

class Approximation
{
    double a, b;
    Points points;
    PointsGenerator generator;
    uint numberOfPoints;

public:
    Approximation(double minX, double maxX, double minY, double maxY, uint numberOfPoints_);
    void calculate();
    double getA() const;
    double getB() const;
};
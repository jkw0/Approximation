#pragma once
#include "Approximation.hpp"

class Spline : public Approximation
{
public:
    Spline(double minX, double maxX, double step);
    void calculate();
    void printCoefficients() const;
};
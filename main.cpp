#include "PointsGenerator.hpp"
#include "Approximation.hpp"
#include <iostream>

int main()
{
    Approximation app(0.0, 20.0, 3.0, 400.0, 50);

    app.calculate();

    std::cout << app.getA() << " " << app.getB() << std::endl;

    return 0;
}
#include "PointsGenerator.hpp"
#include "Approximation.hpp"
#include <iostream>

int main()
{
    Approximation app(99.0, 130.0, 5.0, 50.0, 1500.0);

    app.calculate();

    std::cout << app.getA() << " " << app.getB() << std::endl;

    return 0;
}
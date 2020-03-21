#include "PointsGenerator.hpp"
#include "Approximation.hpp"
#include <iostream>

int main()
{
    Approximation app(0.0, 5.0, 0.2);

    app.calculate();

    std::cout << app.getA() << " " << app.getB() << std::endl;

    return 0;
}
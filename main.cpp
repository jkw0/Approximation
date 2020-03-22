#include "PointsGenerator.hpp"
#include "Approximation.hpp"

int main()
{
    Approximation app(0.0, 5.0, 0.5);

    app.calculate();
    app.printCoefficients();

    return 0;
}
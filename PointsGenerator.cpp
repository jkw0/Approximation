#include "PointsGenerator.hpp"
#include <random>
#include <iostream>

PointsGenerator::PointsGenerator(PointsGenerator::Settings settings_)
    : settings(settings_)
{
}

Points PointsGenerator::generatePoints(uint numberOfPoints)
{
    Points points;
    for (auto i = 0; i < numberOfPoints; ++i)
        points.insert(generateOnePoint());

    return points;
}

void PointsGenerator::setNewSettings(PointsGenerator::Settings settings_)
{
    settings = settings_;
}

/****************************/

double PointsGenerator::generateRandomNumber(double min, double max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(min, max);

    return dis(gen);
}

Point PointsGenerator::generateOnePoint()
{
    static double valueX = settings.minX;
    double x = valueX;
    valueX += 0.5;

    double y = generateRandomNumber(settings.minY, settings.maxY); //*exp

    std::cout << x << " " << y << std::endl;

    return Point(x,y);
}


AxisX generateAxisX(double min, double max, double step)
{
    AxisX axisX{};
    for(auto x = min; x <= max; x+=step)
    {
        axisX.push_back(x);
    }
    return axisX;
}

AxisX PointsGenerator::generateAxisX(double min, uint32_t numOfPoints, double step)
{
    AxisX axisX{};
    for(auto i = 0; i < numOfPoints; ++i)
    {
        axisX.push_back(min+i*step);
    }

    // worse function ;) wink wink
    // for(auto x = min; x < min + numOfPoints*step; x+=step)
    // {
    //     axisX.push_back(x);
    // }

    return axisX;
}

AxisY PointsGenerator::generateAxisY(AxisX axisX, double coeffA, double coeffB, double coeffRandom)
{
    AxisY axisY{};
    
    for(auto x : axisX)
    {
        axisY.push_back(coeffA*exp(coeffB*x) + coeffRandom*generateRandomNumber(0, 5.0));
    }
    return axisY;
}

Points PointsGenerator::generateDataset(double /*min*/, double /*max*/, double /*step*/, double /*coeffA*/, double /*coeffB*/, double /*coeffRandom*/ )
{
    //!@TODO @Justynka please implement this function
}

Points PointsGenerator::generateDataset(double min, double step, uint32_t numOfPoints, double coeffA, double coeffB, double coeffRandom )
{
    AxisX axisX = generateAxisX(min, numOfPoints, step);
    AxisY axisY = generateAxisY(axisX, coeffA, coeffB, coeffRandom);

    Points points{};
    for(auto i = 0; i < numOfPoints; ++i)
    {
        points.insert({axisX.at(i), axisY.at(i)});
        std::cout << axisX.at(i) << " " << axisY.at(i) << std::endl;
    }

    return points;
}
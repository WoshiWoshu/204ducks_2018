/*
** EPITECH PROJECT, 2019
** 204ducks
** File description:
** ducks functions
*/

#include <utility>
#include <cmath>

std::pair<double, double> averageTime(double a)
{
    double time((3 / 4.) + (a * (3 / 8.)));
    double minute(std::floor(time));
    double second((time - minute) * 60);
    std::pair<double, double> averageTime(std::make_pair(minute, second));

    return averageTime;
}

double standardDeviation(double a)
{
    double deviation(0.0);
    double dx(0.001);
    int n(100 / dx);
    double averageRT(3. / 4. + 3 * a / 8);
    double t(0.0);

    for (int i = 0; i < n; ++i) {
        t = (i * dx);
        deviation += std::pow((t - averageRT), 2) * (a * exp(-t) +
        (4 - 3 * a) * exp(-2 * t) + (2 * a - 4) * exp(-4 * t));
    }
    deviation = std::sqrt(deviation * dx);
    return deviation;
}

std::pair<double, double> ducksReturnTime(double a, double percentage)
{
    double deviation(0.0);
    double dx(0.0001);
    double t(0.0);
    int i(0);
    std::pair<double, double> returnTime({0.0, 0.0});
    
    while (deviation < percentage) {
        t = (i * dx);
        deviation += (a * exp(-t) + (4 - 3 * a) * exp(-2 * t)
        + (2 * a - 4) * exp(-4 * t)) * dx;
        ++i;
    }
    returnTime = std::make_pair(std::floor(t), (t - std::floor(t)) * 60);
    return returnTime;
}

double ducksPercentageTime(double a, double minute)
{
    double deviation(0.0);
    double dx(0.0001);
    double t(0.0);

    for (int i = 0; i * dx < minute; ++i) {
        t = (i * dx);
        deviation += (a * exp(-t) + (4 - 3 * a) * exp(-2 * t)
        + (2 * a - 4) * exp(-4 * t)) * dx;
    }
    deviation*=100;
    return deviation;
}

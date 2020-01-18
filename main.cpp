/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include <iostream>
#include <cstring>
#include <iomanip>
#include <sstream>
#include "Ducks.hpp"

static void displayHelp(void)
{
    std::cout << "USAGE" << std::endl;
    std::cout << '\t' << "./204ducks a" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl << "\ta\tconstant" << std::endl;
}

static void ducks(double a)
{
    std::pair<double, double> time(averageTime(a));

    std::cout << std::fixed << std::setprecision(0) << "Average return time: "
              << time.first << "m " << time.second << "s" << std::endl;
    std::cout << std::fixed << std::setprecision(3)
              << "Standard deviation: " << standardDeviation(a) << std::endl;
    time = ducksReturnTime(a, 0.5);
    std::cout << std::fixed << std::setprecision(0)
              << "Time after which 50% of the ducks are back: "
              << time.first << "m " << time.second <<  "s" << std::endl;
    time = ducksReturnTime(a, 0.99);
    std::cout << std::fixed << std::setprecision(0)
              << "Time after which 99% of the ducks are back: "
              << time.first << "m " << time.second <<  "s" << std::endl;
    std::cout << std::fixed << std::setprecision(1)
              << "Percentage of ducks back after 1 minute: "
              << ducksPercentageTime(a, 1) << "%" << std::endl;
    std::cout << std::fixed << std::setprecision(1)
              << "Percentage of ducks back after 2 minutes: "
              << ducksPercentageTime(a, 2) << "%" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    if (strcmp(av[1], "-h") == 0) {
        displayHelp();
        return 0;
    }
    for (int i = 0; av[1][i] != '\0'; ++i)
        if ((av[1][i] < '0' || av[1][i] > '9')
        && av[1][i] != '.')
            return 84;
    if (strcmp(av[1], ".") == 0)
        return 84;
    if (std::atof(av[1]) > 2.5)
        return 84;
    ducks(std::atof(av[1]));
    return 0;
}

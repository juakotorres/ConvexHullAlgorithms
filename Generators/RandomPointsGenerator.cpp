//
// Created by juaki on 5/15/17.
//


#include <stdlib.h>
#include <time.h>
#include "RandomPointsGenerator.h"

std::vector<Point<double>> *
RandomPointsGenerator::generateRandomPoints(double numberOfPoints, double maxX, double maxY) {
    std::vector<Point<double>> *cloud = new std::vector<Point<double>>();
    double xpoint;
    double ypoint;

    srand (time(NULL));

    for (int i = 0; i < numberOfPoints; i++) {
        xpoint = maxX * ((double) rand()) / (double) RAND_MAX;
        ypoint = maxY * ((double) rand()) / (double) RAND_MAX;
        Point<double> pushPoint(xpoint, ypoint);

        cloud->push_back(pushPoint);
    }

    return cloud;
}

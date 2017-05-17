//
// Created by juaki on 5/15/17.
//

#ifndef TAREA1_RANDOMPOINTSGENERATOR_H
#define TAREA1_RANDOMPOINTSGENERATOR_H


#include <vector>
#include <cstdlib>
#include "../Geometry/Point.h"

class RandomPointsGenerator {
public:
    std::vector<Point<double>> *generateRandomPoints(double numberOfPoints, double maxX, double maxY);
};


#endif //TAREA1_RANDOMPOINTSGENERATOR_H

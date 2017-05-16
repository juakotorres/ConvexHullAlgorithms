//
// Created by juaki on 5/15/17.
//

#ifndef TAREA1_QUICKHULL_H
#define TAREA1_QUICKHULL_H


#include <vector>
#include "../Geometry/Point.h"
#include "../Geometry/Polygon.h"
#include "ConvexHullAlgorithm.h"

class QuickHull : public ConvexHullAlgorithm {
public:
    QuickHull();
    virtual void executeAlgorithm(std::vector<Point<double>> points);
};


#endif //TAREA1_QUICKHULL_H

//
// Created by juaki on 5/15/17.
//

#ifndef TAREA1_CONVEXHULLALGORITHM_H
#define TAREA1_CONVEXHULLALGORITHM_H


#include "../Geometry/Polygon.h"

class ConvexHullAlgorithm {
public:
    ConvexHullAlgorithm();
    Polygon<double> *getConvexHull();
    virtual void executeAlgorithm(std::vector<Point<double>> points);
protected:
    Point<double> leftMostPoint();
    Point<double> rightMostPoint();
    std::vector<Point<double>> *cloud;
    Polygon<double> *convexHull;


};


#endif //TAREA1_CONVEXHULLALGORITHM_H

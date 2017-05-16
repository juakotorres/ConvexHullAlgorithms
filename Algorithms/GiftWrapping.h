//
// Created by juaki on 5/15/17.
//

#ifndef TAREA1_GIFTWRAPPING_H
#define TAREA1_GIFTWRAPPING_H


#include <vector>
#include "../Geometry/Point.h"
#include "../Geometry/Polygon.h"
#include "../Geometry/JVector.h"
#include "ConvexHullAlgorithm.h"

class GiftWrapping : public ConvexHullAlgorithm{
public:
    GiftWrapping();
    virtual void executeAlgorithm(std::vector<Point<double>> points);

    Point<double> lookForPosibleCandidate(std::vector<Point<double>> *pVector);

    bool notInConvexHull(std::vector<Point<double>> *pVector, Point<double> point);
};


#endif //TAREA1_GIFTWRAPPING_H

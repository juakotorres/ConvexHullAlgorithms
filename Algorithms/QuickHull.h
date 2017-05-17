//
// Created by juaki on 5/15/17.
//

#ifndef TAREA1_QUICKHULL_H
#define TAREA1_QUICKHULL_H


#include <vector>
#include <queue>
#include "../Geometry/Point.h"
#include "../Geometry/Polygon.h"
#include "ConvexHullAlgorithm.h"

class QuickHull : public ConvexHullAlgorithm {
public:
    QuickHull();
    virtual void executeAlgorithm(std::vector<Point<double>> points);
private:
    std::vector<Point<double>> *getRightSet(Point<double> point, Point<double> pointB, std::vector<Point<double>> vector);
    void quickHullAux(std::vector<Point<double>> *pVector, Point<double> point, Point<double> pointB,
                      std::queue<Point<double>> *pQueue);
    Point<double> furthestPoint(std::vector<Point<double>> *pVector, Point<double> point, Point<double> pointB);
    double getDistance(Point<double> pointA, Point<double> pointB, Point<double> pointC);
};


#endif //TAREA1_QUICKHULL_H

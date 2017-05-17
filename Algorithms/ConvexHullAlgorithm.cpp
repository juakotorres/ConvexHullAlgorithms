//

// Created by juaki on 5/15/17.
//

#include "ConvexHullAlgorithm.h"

ConvexHullAlgorithm::ConvexHullAlgorithm() {
    convexHull = new Polygon<double>();
}

Polygon<double> *ConvexHullAlgorithm::getConvexHull() {
    return convexHull;
}

void ConvexHullAlgorithm::executeAlgorithm(std::vector<Point<double>> points) {
    cloud = new std::vector<Point<double>>(points);
}

/**
 * Look for leftmost point in list given.
 * @return Point leftmost in the set, null if not set.
 */
Point<double> ConvexHullAlgorithm::leftMostPoint() {
    double minX = cloud->front().getX();
    Point<double> result = cloud->front();

    for (int i = 1; i < cloud->size(); i++){
        if(minX > (cloud->at((unsigned long) i)).getX()){
            result = (cloud->at((unsigned long) i));
            minX = result.getX();
        }
    }

    return result;
}

/**
 * Look for rightmost point in list given.
 * @return Point leftmost in the set, null if not set.
 */
Point<double> ConvexHullAlgorithm::rightMostPoint() {
    double maxX = cloud->front().getX();
    Point<double> result = cloud->front();

    for (int i = 1; i < cloud->size(); i++){
        if(maxX < (cloud->at((unsigned long) i)).getX()){
            result = (cloud->at((unsigned long) i));
            maxX = result.getX();
        }
    }

    return result;
}


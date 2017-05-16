//
// Created by juaki on 5/15/17.
//

#include "QuickHull.h"

QuickHull::QuickHull() {
    QuickHull::ConvexHullAlgorithm();
}

void QuickHull::executeAlgorithm(std::vector<Point<double>> points) {
    ConvexHullAlgorithm::executeAlgorithm(points);
}

//
// Created by juaki on 5/15/17.
//

#include <queue>
#include "QuickHull.h"

QuickHull::QuickHull() {
    QuickHull::ConvexHullAlgorithm();
}

void QuickHull::executeAlgorithm(std::vector<Point<double>> points) {
    ConvexHullAlgorithm::executeAlgorithm(points);

    /* Inicialmente buscamos los puntos mas alejados */
    Point<double> pointB = rightMostPoint();
    Point<double> pointA = leftMostPoint();

    /* Separamos el conjunto en dos conjuntos de acuerdo a la regla de estar a la derecha de la recta. */
    std::vector<Point<double>> *rightSetAB = getRightSet(pointA, pointB, points);
    std::vector<Point<double>> *rightSetBA = getRightSet(pointB, pointA, points);


    /* Cola con los puntos de la cerradura convexa. */
    std::queue<Point<double>> *finalConvexHull = new std::queue<Point<double>>();
    quickHullAux(rightSetBA, pointB, pointA, finalConvexHull);
    quickHullAux(rightSetAB, pointA, pointB, finalConvexHull);

    /* Liberamos memoria de los sets creados. */
    delete(rightSetAB);
    delete(rightSetBA);

    /* Los puntos se encuentran ccw en la cola entregada. */

    while(!finalConvexHull->empty()){
        Point<double> actual = finalConvexHull->front();
        finalConvexHull->pop();

        convexHull->addPoint(actual);
    }

    /* Liberamos memoria de la cola. */
    delete(finalConvexHull);

}

std::vector<Point<double>> *
QuickHull::getRightSet(Point<double> pointA, Point<double> pointB, std::vector<Point<double>> set) {
    Vector<double> vectorAB(pointA, pointB);
    std::vector<Point<double>> *newSet = new std::vector<Point<double>>();

    for (unsigned long i = 0; i < set.size(); i++){
        Point<double> actualPoint = set.at(i);
        Vector<double> vectorPB(actualPoint, pointB);

        double z = vectorPB.cruz(vectorAB).getZ();

        /* A la derecha de la recta. */
        if(z > 0)
            newSet->push_back(actualPoint);

    }

    return newSet;
}

/**
 * Realiza el algoritmo de quickhull recursivo.
 */
void QuickHull::quickHullAux(std::vector<Point<double>> *Set, Point<double> pointA, Point<double> pointB,
                             std::queue<Point<double>> *actualConvexHull) {

    /* Caso en que el set restante sea vacio, agregamos punto A al set.*/
    if(Set->size() == 0) {
        actualConvexHull->push(pointA);
        return;
    }

    /* Buscamos punto mas alejado de la recta AB. */
    Point<double> pointC = furthestPoint(Set, pointA, pointB);

    /* Separamos el conjunto en dos conjuntos de acuerdo a la regla de estar a la derecha de la recta. */
    std::vector<Point<double>> *rightSetAC = getRightSet(pointA, pointC, *Set);
    std::vector<Point<double>> *rightSetCB = getRightSet(pointC, pointB, *Set);

    /* Realizamos el quickhull recursivo. */
    quickHullAux(rightSetAC, pointB, pointA, actualConvexHull);
    quickHullAux(rightSetCB, pointA, pointB, actualConvexHull);

    /* Liberamos memoria no usada a futuro.*/
    delete(rightSetAC);
    delete(rightSetCB);
}

/**
 * Busca el punto mas lejano en el set a la recta AB.
 */
Point<double> QuickHull::furthestPoint(std::vector<Point<double>> *Set, Point<double> pointA, Point<double> pointB) {

    Point<double> chosenPoint = Set->at(0);
    double maxDistance = getDistance(pointA, pointB, chosenPoint);

    for(unsigned long i = 1; i < Set->size(); i++){
        Point<double> posibleMaxPoint = Set->at(i);
        double pointDistance = getDistance(pointA, pointB, posibleMaxPoint);

        if(pointDistance > maxDistance){
            maxDistance = pointDistance;
            chosenPoint = posibleMaxPoint;
        }
    }

    return chosenPoint;
}

/**
 * Da la distancia entre el punto C y la recta formada por los puntos A y B.
 */
double QuickHull::getDistance(Point<double> pointA, Point<double> pointB, Point<double> pointC) {
    double x1 = pointA.getX(), y1 = pointA.getY(),
           x2 = pointB.getX(), y2 = pointB.getY(),
           x0 = pointC.getX(), y0 = pointC.getY();


    return abs((y2 - y1)*x0 - (x2 - x1)*y0 + x2*y1 - y2*x1)/(sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2)));
}


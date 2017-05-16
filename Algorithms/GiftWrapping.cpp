//
// Created by juaki on 5/15/17.
//

#include <algorithm>
#include "GiftWrapping.h"

GiftWrapping::GiftWrapping() {
    ConvexHullAlgorithm();
}

void GiftWrapping::executeAlgorithm(std::vector<Point<double>> points) {
    ConvexHullAlgorithm::executeAlgorithm(points);

    Point<double> leftmost = leftMostPoint();
    std::vector<Point<double>> *auxConvexHull = new std::vector<Point<double>>();

    Point<double> auxPoint(leftmost.getX(), leftmost.getY() + 1);
    Vector<double> auxVector(leftmost, auxPoint);
    Point<double> selected = leftmost;
    unsigned long j = 1;

    /* GiftWrapping */
    while(!(auxConvexHull->front() == auxPoint)){
        /* buscamos el punto que tenga todos los demas puntos
         * a su izquierda, esto se hace buscando el angulo mas pequeno */

        /* Agregamos punto a punto los que pertenecen a la cerradura */
        auxConvexHull->push_back(selected);

        Point<double> nextCandidate = lookForPosibleCandidate(auxConvexHull);
        Vector<double> localVector(nextCandidate, auxConvexHull->at(j - 1));
        double candidateAngle = localVector.getAngle(auxVector);

        for(unsigned long i = 0; i < cloud->size(); i++){
            Point<double> posibleChange = cloud->at(i);
            Vector<double> posibleChangeVector(posibleChange, auxConvexHull->at(j - 1));
            double posibleNewAngle = posibleChangeVector.getAngle(auxVector);

            /* Cambiamos candidato si es mejor que el anterior, ccw es la busqueda. */
            if((candidateAngle > posibleNewAngle )
               && (posibleChange == auxConvexHull->at(0) || notInConvexHull(auxConvexHull, posibleChange))){
                nextCandidate = posibleChange;
                candidateAngle = posibleNewAngle;
            }
        }

        selected = nextCandidate;
        j++;
    }

    /* Guardamos cerradura en el polygono a entregar. */
    for(unsigned long k = 0; k < auxConvexHull->size(); k++)
        convexHull->addPoint(auxConvexHull->at(k));

}

Point<double> GiftWrapping::lookForPosibleCandidate(std::vector<Point<double>> *convexHull) {

    for (int i = 0; i < cloud->size(); i++){
        Point<double> actual = cloud->at((unsigned long) i);
        if (std::find(convexHull->begin(), convexHull->end(), actual) == convexHull->end())
            return actual;
    }
    return Point<double>(0, 0);
}

bool GiftWrapping::notInConvexHull(std::vector<Point<double>> *convexHull, Point<double> point) {
    return std::find(convexHull->begin(), convexHull->end(), point) != convexHull->end();
}

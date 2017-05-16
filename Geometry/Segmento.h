//
// Created by juaki on 3/23/17.
//

#ifndef TAREA1_SEGMENTO_H
#define TAREA1_SEGMENTO_H

#include "Point.h"
#include "JVector.h"
#include <math.h>

template <class T>
class Segmento{
private:
    Point<T> pointA = Point<T>(T(), T());
    Point<T> pointB = Point<T>(T(), T());
    T largo;
public:
    Segmento(Point<T> &x, Point<T> &y);
    Segmento(T a1, T a2, T b1, T b2);
    Segmento(const Segmento& other);
    T orientacion(Point<T> point);
    bool intersectPoint(Point<T> point);
    T getLargo();
};

template <class T>
Segmento<T>::Segmento(Point<T> &x, Point<T> &y) {

    if(x.getY() < y.getY()) {
        this->pointA = x;
        this->pointB = y;
    } else {
        this->pointA = y;
        this->pointB = x;
    }

    this->largo = (T) sqrt(pow(x.getY() - y.getY(), 2) + pow(x.getX() - y.getX() , 2));
}


template <class T>
Segmento<T>::Segmento(T a1, T a2, T b1, T b2) {

    Point<T> a(a1, a2);
    Point<T> b(b1, b2);

    if(a2 < b2) {
        this->pointA = a;
        this->pointB = b;
    } else {
        this->pointB = a;
        this->pointA = b;
    }

    this->largo = (T) sqrt(pow(a2 - b2, 2) + pow(a1 - b1, 2));
}

template <class T>
Segmento<T>::Segmento(const Segmento &other) {
    this->pointA = other.pointA;
    this->pointB = other.pointB;
    this->largo = other.largo;
}

/*
 * Derecha +, Izquierda -, colineal 0
 */
template <class T>
T Segmento<T>::orientacion(Point<T> point){
    Vector<T> vectorBA(pointB.getX() - pointA.getX(), pointB.getY() - pointA.getY(), 0);
    Vector<T> vectorCA(point.getX() - pointA.getX(), point.getY() - pointA.getY(), 0);

    Vector<T> result = vectorCA.cruz(vectorBA);

    return result.getZ();
}

template <class T>
bool Segmento<T>::intersectPoint(Point<T> point){
    if (pointB.getX() == pointA.getX()){
        if( pointB.getY() < pointA.getY()){
            return pointB.getY() < point.getY() && pointA.getY() > point.getY();
        }

        return pointB.getY() > point.getY() && pointA.getY() < point.getY();
    }

    return pointA.getX() < point.getX() && pointB.getX() > point.getX();
}

template <class T>
T Segmento<T>::getLargo() {
    return largo;
}

#endif //TAREA1_SEGMENTO_H

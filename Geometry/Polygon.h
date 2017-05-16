//
// Created by juaki on 3/28/17.
//

#ifndef TAREA1_POLYGON_H
#define TAREA1_POLYGON_H

#include <vector>
#include "Point.h"
#include "Segmento.h"

template <class T>
class Polygon{
private:
    std::vector<Point<T>> vertices;
    Point<T> boundingPoint();
public:
    Polygon();
    Polygon(std::vector<Point<T>> x);
    Polygon(const Polygon& other);
    void addPoint(Point<T> point);
    bool intersection(Point<T> point);
    T area();
    bool ccw();
};

template <class T>
Polygon<T>::Polygon() {
    this->vertices = std::vector<Point<T>>();
}

template <class T>
Polygon<T>::Polygon(std::vector<Point<T>> x) {
    this->vertices = x;
}

template <class T>
Polygon<T>::Polygon(const Polygon& other) {
    this->vertices = other.vertices;
}

template <class T>
void Polygon<T>::addPoint(Point<T> point) {
    this->vertices.insert(this->vertices.end(), point);
}

template <class T>
Point<T> Polygon<T>::boundingPoint() {
    Point<T> chosenPoint = vertices[0];

    for(int i = 1; i < vertices.size(); i++){
        Point<T> actualPoint = vertices[i];

        if(chosenPoint.getX() > actualPoint.getX()){
            chosenPoint = actualPoint;
        }
    }

    Point<T> returnPoint(chosenPoint.getX() - 10, chosenPoint.getY());

    return returnPoint;
}

template <class T>
bool Polygon<T>::intersection(Point<T> point) {
    /*
     * elegimos punto fuera del polygono.
     */
    Point<T> polygonPoint = boundingPoint();
    /*
     * intersectar recta con aristas del polygono
     * si las intersecciones son impares el punto esta dentro del polygono.
     */
    int collides = 0;
    Segmento<T> recta(point, polygonPoint);

    for(int i = 0; i < vertices.size() - 1; i++){
        T a = recta.orientacion(vertices[i]);
        T b = recta.orientacion(vertices[i+1]);

        if(a*b >= 0){
            collides++;
        }
    }

    return collides%2 != 0;
}

template <class T>
bool Polygon<T>::ccw(){
    T property = 0;

    for(int i = 0; i < vertices.size(); i++){
        Point<T> point1 = vertices[i];
        Point<T> point2 = vertices[(i+1)%vertices.size()];
        Point<T> point3 = vertices[(i+2)%vertices.size()];

        Vector<T> a(point1.getX() - point2.getX(), point1.getY() - point2.getY(), 0);
        Vector<T> b(point3.getX() - point2.getX(), point3.getY() - point2.getY(), 0);

        Vector<T> result = b.cruz(a);

        property += result.getZ();
    }

    return property > 0;
}



template <class T>
T Polygon<T>::area(){

    T result = 0;

    for(int i = 0; i < vertices.size(); i++){
        Point<T> point2 = vertices[i];
        Point<T> point1 = vertices[i+1%vertices.size()];
        result += (point1.getX() + point2.getX()) * (point1.getY() - point2.getY());
    }

    return result / 2;

}

#endif //TAREA1_POLYGON_H

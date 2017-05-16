//
// Created by juaki on 3/23/17.
//

#ifndef TAREA1_JVECTOR_H
#define TAREA1_JVECTOR_H

#include "math.h"

template <class T>
class Vector{
private:

    T valueX;
    T valueY;
    T valueZ;
    T magnitud;
public:
    Vector(T x, T y, T z);
    //Vector(T x, T y);
    Vector(const Vector& other);
    Vector cruz(Vector<T> lhs);
    T punto(Vector<T> lhs);
    T &getX();
    T &getY();
    T &getZ();
    void normalizar();
    T &getLargo();

    Vector(Point<T> x, Point<T> y);

    double getAngle(Vector<T> vector);
};


template <class T>
Vector<T>::Vector(T x, T y, T z) {
    this->valueX = x;
    this->valueY = y;
    this->valueZ = z;

    this->magnitud = sqrt(x*x + y*y + z*z);
}

template <class T>
Vector<T>::Vector(Point<T> x, Point<T> y) {
    this->valueX = x.getX() - y.getX();
    this->valueY = x.getY() - y.getY();
    this->valueZ = 0;

    this->magnitud = sqrt(valueX*valueX + valueY*valueY + valueZ*valueZ);
}

template <class T>
Vector<T>::Vector(const Vector &other) {
    this->valueX = other.valueX;
    this->valueY = other.valueY;
    this->valueZ = other.valueZ;
}

template <class T>
Vector<T> Vector<T>::cruz(Vector<T> a) {
    T aux1 = a.valueX;
    T aux2 = a.valueY;
    T aux3 = a.valueZ;

    a.valueX = this->valueY * aux3 - this->valueZ * aux2;
    a.valueY = this->valueZ * aux1 - this->valueX * aux3;
    a.valueZ = this->valueX * aux2- this->valueY * aux1;
    return a;
}

template <class T>
T Vector<T>::punto(Vector<T> a) {
    return this->valueX*a.valueX + this->valueY*a.valueY + this->valueZ*a.valueZ;
}

template <class T>
T &Vector<T>::getLargo(){
    return this->magnitud;
}

template <class T>
void Vector<T>::normalizar() {
    T largo = sqrt(this->valueX*this->valueX + this->valueY*this->valueY + this->valueZ*this->valueZ);

    this->valueX /= largo;
    this->valueY /= largo;
    this->valueZ /= largo;
}

template <class T>
T &Vector<T>::getX() {
    return this->valueX;
}

template <class T>
T &Vector<T>::getY() {
    return this->valueY;
}

template <class T>
T &Vector<T>::getZ() {
    return this->valueZ;
}

template <class T>
double Vector<T>::getAngle(Vector<T> vector) {
    return acos(this->punto(vector) / (this->magnitud * vector.magnitud));
}


#endif //TAREA1_JVECTOR_H

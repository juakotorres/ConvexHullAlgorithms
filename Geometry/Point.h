#ifndef TAREA1_POINT_H
#define TAREA1_POINT_H

template <class T>
class Point{
private:
    T valueX;
    T valueY;
public:
    Point(T x, T y);
    Point(const Point& other);
    Point operator+(Point<T> lhs);
    Point operator-(Point a);
    Point &operator+=(Point<T> lhs);
    Point &operator-=(Point<T> lhs);
    bool operator==(Point<T> lhs);
    T &getX();
    T &getY();

    T getZ();
};


template <class T>
Point<T>::Point(T x, T y) {
    this->valueX = x;
    this->valueY = y;
}

template <class T>
Point<T>::Point(const Point &other) {
    this->valueX = other.valueX;
    this->valueY = other.valueY;
}

template <class T>
Point<T> Point<T>::operator+(Point<T> a) {
    a.valueX += this->valueX;
    a.valueY += this->valueY;
    return a;
}

template <class T>
Point<T> &Point<T>::operator+=(Point<T> a) {
    this->valueX += a.valueX;
    this->valueY += a.valueY;
    return *this;
}


template <typename T>
Point<T> Point<T>::operator-(Point<T> a) {
    a.valueX = this->valueX - a.valueX;
    a.valueY = this->valueY - a.valueY;
    return a;
}

template <class T>
Point<T> &Point<T>::operator-=(Point<T> a) {
    this->valueX -= a.valueX;
    this->valueY -= a.valueY;
    return *this;
}

template <class T>
bool Point<T>::operator==(Point<T> a){
    return this->valueX == a.valueX && this->valueY == a.valueY;
}

template <class T>
T &Point<T>::getX() {
    return this->valueX;
}

template <class T>
T &Point<T>::getY() {
    return this->valueY;
}


#endif //TAREA1_POINT_H

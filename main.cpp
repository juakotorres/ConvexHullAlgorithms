#include <iostream>
#include "Geometry/Point.h"
#include "Geometry/JVector.h"
#include "Geometry/Segmento.h"
#include "Geometry/Polygon.h"

int main() {
    /* Tests tarea 2 */






    /* Tests tarea 1 *//*
    *//* Ejemplos de puntos en el plano 2D *//*
    Point<int> myPoint2(3,6);
    Point<int> myPoint3(8,6);
    Point<int> result = myPoint3 + myPoint2;
    Point<int> result2 = myPoint2 - myPoint3;
    printf("----------------------------------\n");
    printf("Test Puntos\n");
    printf("----------------------------------\n");
    printf("Point2(3,6) == Point3(8,6): %d\n", myPoint2==myPoint3);
    printf("Point3: (%d, %d)\n",myPoint3.getX() ,myPoint3.getY() );
    printf("Point3 + Point2: (%d, %d)\n",result.getX() ,result.getY() );
    printf("Point2: (%d, %d)\n",myPoint2.getX() ,myPoint2.getY() );
    printf("Point2 - Point3: (%d, %d)\n",result2.getX() ,result2.getY() );


    *//* Point double *//*
    Point<double> myPoint(2.5, 2);
    Point<double> doublePoint(1.5,8.80999);
    Point<double> doublePoint2(3.2, 6.6);
    Point<double> sumPoints = doublePoint + doublePoint2;

    printf("myPoint (%f, %f)\n",myPoint.getX() ,myPoint.getY());
    printf("(1.5, 8.80999) + (3.2, 6.6) = (%f, %f)\n",sumPoints.getX() ,sumPoints.getY());
    printf("myPoint == myPoint: %d\n", myPoint == myPoint);

    *//* Vectores *//*

    Vector<double> vector(2.4,2.4,1.1);
    Vector<double> vector2(4,3.9427,1);
    Vector<double> pequeno1(0.000000000001, 0.00000000002, 0.00000000003);
    Vector<double> pequeno2(0.000000000004, 0.00000000005, 0.00000000006);
    Vector<double> grande1(4000000000001, 400000000002, 400000000003);
    Vector<double> grande2(3000000000001, 300000000002, 300000000003);
    Vector<int> grandeInt1(400000000, 500000000, 100000000);
    Vector<int> grandeInt2(300000000, 300000000, 300000000);
    Vector<int> Int1(40, 50, 10);
    Vector<int> Int2(30, 30, 30);


    Vector<int> vectorInt(2,4,0);
    Vector<int> vectorInt2(9,7,0);

    Vector<double> resultVector = vector.cruz(vector2);
    double resultPunto = vector.punto(vector2);
    Vector<int> resultVectorInt = vectorInt.cruz(vectorInt2);
    int resultInt = vectorInt.punto(vectorInt2);

    Vector<int> grandeCruz = grandeInt1.cruz(grandeInt2);
    Vector<int> intResult = Int1.cruz(Int2);

    printf("----------------------------------\n");
    printf("Test Vectores\n");
    printf("----------------------------------\n");

    printf("\nNormalizar vectores\n");
    vector.normalizar();
    vectorInt.normalizar();
    printf("Vector(2,4,0) normalizado : (%d, %d, %d)\n",vectorInt.getX() ,vectorInt.getY(), vectorInt.getZ());
    printf("Vector(2.4,2.4,1.1) normalizado : (%f, %f, %f)\n",vector.getX() ,vector.getY(), vector.getZ());

    printf("\nProducto cruz y punto vectores\n");
    printf("Vector(2,4,0) x Vector(9,7,0): (%d, %d, %d)\n",resultVectorInt.getX() ,resultVectorInt.getY(), resultVectorInt.getZ() );
    printf("Vector(2,4,0) . Vector(9,7,0): %d\n", resultInt);
    printf("Vector(2.4,2.4,1.1) x Vector(4, 3.9427, 1): (%f, %f, %f)\n",resultVector.getX() ,resultVector.getY(), resultVector.getZ() );
    printf("Vector(2.4,2.4,1.1) . Vector(4, 3.9427, 1): %f\n", resultPunto);

    Vector<double> pequenoresult = pequeno1.cruz(pequeno2);
    Vector<double> granderesult = grande1.cruz(grande2);

    printf("Vectores double pequeños producto cruz : (%f, %f, %f), punto: %f\n", pequenoresult.getX(), pequenoresult.getY(), pequenoresult.getZ(), pequeno1.punto(pequeno2));
    printf("Vectores double grandes producto cruz : (%f, %f, %f), punto: %f\n", granderesult.getX(), granderesult.getY(), granderesult.getZ(), grande1.punto(grande2));

    printf("Vectores int grandes producto cruz : (%d, %d, %d), punto: %d\n", grandeCruz.getX(), grandeCruz.getY(), grandeCruz.getZ(), grandeInt1.punto(grandeInt2));
    printf("Vectores int menos exponente producto cruz : (%d, %d, %d), punto: %d\n", intResult.getX(), intResult.getY(), intResult.getZ(), Int1.punto(Int2));


    *//* Segmentos *//*

    Point<int> A(1,1);
    Point<int> B(3,3);
    Point<int> C(4,2);
    Point<int> D(-3, 2);
    Point<int> E(2,2);
    Point<double> F(1.1,0.5);
    Point<double> G(1.5, 0.4);
    Point<double> H(2.2, 0.45);
    Point<double> I(1.099, 0.499);
    Point<double> J(1.499, 0.401);
    Segmento<double> segmentoDouble(F,G);
    Segmento<int> segmentoPrueba(A,B);

    int largo = segmentoPrueba.getLargo();
    printf("----------------------------------\n");
    printf("Test Segmento\n");
    printf("----------------------------------\n");
    printf("Segmento int AB\n");
    printf("A(1,1) B(3,3) C(4,2) D(-3, 2) E(2,2)\n");
    printf("largo segmento: %d \n", largo);
    printf("Orientacion puntos con respecto a segmento AB\n");
    printf("AB - C : %d\n", segmentoPrueba.orientacion(C));
    printf("AB - D : %d\n", segmentoPrueba.orientacion(D));
    printf("AB - E : %d\n", segmentoPrueba.orientacion(E));

    printf("Segmento double FG\n");
    printf("F(1.1,0.5) G(1.5, 0.4) H(2.2,0.45) I(1.099, 0.499) J(1.499, 0.401)\n");
    printf("largo segmento: %f \n", segmentoDouble.getLargo());
    printf("Orientacion puntos con respecto a segmento AB\n");
    printf("FG - H : %f\n", segmentoDouble.orientacion(H));
    printf("FG - I : %f\n", segmentoDouble.orientacion(I));
    printf("FG - J : %f\n", segmentoDouble.orientacion(J));

    *//* Polygono *//*

    printf("----------------------------------\n");
    printf("Test Poligono\n");
    printf("----------------------------------\n");
    Polygon<int> myPolygon;

    myPolygon.addPoint(A);
    myPolygon.addPoint(C);
    myPolygon.addPoint(B);

    Point<int> intPoint(0,0);
    printf("Poligono\n");
    printf("A(1,1) B(3,3) C(4,2)\n");
    printf("punto (0,0) está en el poligono? : %d\n", myPolygon.intersection(intPoint));
    printf("El poligono está formado ccw?  : %d\n", myPolygon.ccw());

    Point<int> T(-6, 1);
    myPolygon.addPoint(T);
    Point<int> intPoint2(-1,2);
    int area = myPolygon.area();

    printf("Se agrega punto T(-6, 1) \n");
    printf("punto (-1,2) está en el poligono?: %d\n", myPolygon.intersection(intPoint2));
    printf("área del polygono: %d\n", area);
    return 0;*/
}
#include <iostream>
#include "Geometry/Point.h"
#include "Geometry/JVector.h"
#include "Geometry/Segmento.h"
#include "Geometry/Polygon.h"
#include "Generators/RandomPointsGenerator.h"
#include "Algorithms/QuickHull.h"
#include "Algorithms/GiftWrapping.h"



struct timespec diff(struct timespec start, struct timespec end)
{
    struct timespec temp;

    if ((end.tv_nsec-start.tv_nsec)<0)
    {
        temp.tv_sec = end.tv_sec-start.tv_sec-1;
        temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    }
    else
    {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }
    return temp;
}


int main() {
    /* Tests tarea 2 */

    RandomPointsGenerator generator;

    std::vector<Point<double>> *cloud = generator.generateRandomPoints(1 << 10, 100, 100);


    GiftWrapping *algorithm1 = new GiftWrapping();
    QuickHull *algorithm2 = new QuickHull();

    /* Debug para ver la nube de puntos. */
    /*for(int i = 0; i < cloud->size(); i++){
        Point<double> a = cloud->at(i);
        printf("Punto  (%f, %f)\n", a.getX(), a.getY());
    }*/
    float tiempo_total_1 = 0;
    float tiempo_total_2 = 0;
    struct timespec t1, t2;;

    time_t inicio;
    time_t t_iteracion;
    clock_gettime(CLOCK_REALTIME, &t1); //empezar a medir tiempo
    algorithm2->executeAlgorithm(*cloud); // ejecutamos QuickHull
    clock_gettime(CLOCK_REALTIME, &t2);//terminar de medir tiempo

    tiempo_total_1 += diff(t1,t2).tv_sec * 1000000000 + diff(t1,t2).tv_nsec;


    clock_gettime(CLOCK_REALTIME, &t1); //empezar a medir tiempo
    algorithm1->executeAlgorithm(*cloud); // ejecutamos GiftWrapping
    clock_gettime(CLOCK_REALTIME, &t2);//terminar de medir tiempo

    tiempo_total_2 += diff(t1,t2).tv_sec * 1000000000 + diff(t1,t2).tv_nsec;

    Polygon<double> *result1 = algorithm2->getConvexHull();
    Polygon<double> *result2 = algorithm1->getConvexHull();
    std::vector<Point<double>> vertices1 = result1->getVertices();
    std::vector<Point<double>> vertices2 = result2->getVertices();

    /* Debug para ver los puntos resultantes. */
    /*for(int i = 0; i < vertices1.size(); i++){
        Point<double> a = vertices1[i];
        printf("QuickHull  (%f, %f)\n", a.getX(), a.getY());
    }
    for(int i = 0; i < vertices2.size(); i++){
        Point<double> a = vertices2[i];
        printf("GiftWrapping  (%f, %f)\n", a.getX(), a.getY());
    }*/

    printf("Las dos cerraduras convexas son iguales? : %d\n", result1->polygonEqual(*result2));
    printf("numberofVertices GiftWrapping : %f \n", result2->numberOfVertices());
    printf("numberofVertices QuickHull : %f \n", result1->numberOfVertices());
    printf("Tiempo ejecucion GiftWrapping: %.3f\n", tiempo_total_2 / 1000000);
    printf("Tiempo ejecucion QuickHull: %.3f\n", tiempo_total_1 / 1000000);

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
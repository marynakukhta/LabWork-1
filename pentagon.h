#ifndef pentagon_h
#define pentagon_h


#endif /* pentagon_h */


#pragma once
#include "figures.h"



class pentagon :public figures
{
public:
    pentagon();
    pentagon(point vert[]);
    ~pentagon();
    double area();
    void form_edges();
    void right_angle();////прямоугольный
};

void pentagon::form_edges()
{
    el[0] = length(с[0], с[1]);
    el[1] = length(с[1], с[2]);
    el[2] = length(с[2], с[3]);
    el[3] = length(с[3], с[4]);
    el[4] = length(с[4], с[0]);
}

pentagon::pentagon()
{
    n = 5;
    el = new double[n];
    с = new point[n];
    for (int i = 0; i < n; ++i)
    {
        srand(i + time(NULL));
        с[i].x = rand() % 20;
        srand(i + 10 + time(NULL));
        с[i].y = rand() % 20;
    }
    form_edges();
}

pentagon::~pentagon()
{
    delete[]el;
    delete[]с;
}

pentagon::pentagon(point vert[])
{
    n = 5;
    el = new double[n];
    с = new point[n];
    for (int i = 0; i < n; ++i)
    {
        с[i] = vert[i];
    }
    form_edges();
}



void pentagon::right_angle()
{
    double sc1 = distance(с[4], с[0], с[1], с[0]);
    double sc2 = distance(с[1], с[2], с[3], с[2]);
    double sc3 = distance(с[2], с[3], с[4], с[3]);
    bool condition1 = el[0] == el[1] && el[1] == el[2] && el[2] == el[3] && el[3] == el[4];
    bool condition2 = abs(sc1 / (el[4] * el[0]) - sc2 / (el[1] * el[2])) <= eps;
    bool condition3 = abs(sc1 / (el[4] * el[0]) - sc3 / (el[2] * el[3])) <= eps;
    (condition1 == true && condition2 == true && condition3 == true) ? std::cout << "Pentagon is right" :
    std::cout << "Pentagon is not right";
}



double pentagon::area()
{
  
    double l1 = length(с[0], с[2]);
    double l2 = length(с[2], с[4]);
    double pa1 = (l1 + el[0] + el[1]) / 2;
    double pa2 = (l1 + l2 + el[4]) / 2;
    double pa3 = (l2 + el[2] + el[3]) / 2;
    double s1 = sqrt(pa1*(pa1 - l1)*(pa1 - el[0])*(pa1 - el[1]));
    double s2 = sqrt(pa2*(pa2 - l1)*(pa2 - l2)*(pa2 - el[4]));
    double s3 = sqrt(pa3*(pa3 - l2)*(pa3 - el[2])*(pa3 - el[3]));
    double result = s1 + s2 + s3;
    std::cout << "Area is " << result;
    return result;
}

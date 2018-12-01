#ifndef quadrangle_h
#define quadrangle_h


#endif /* quadrangle_h */

#pragma once
#include "figures.h"



class quadrangle :public figures
{
public:
    quadrangle();
    quadrangle(point vert[]);
    ~quadrangle();
    bool check_parallelogram();
    double area();
    void form_edges();
    void check_trapeze();
    void printP();
    void check_rhombus();
    void check_rectangle();
    void check_square();
};


void quadrangle::form_edges()
{
    
    el[0] = length(с[0], с[1]);
    el[1] = length(с[1], с[2]);
    el[2] = length(с[2], с[3]);
    el[3] = length(с[3], с[0]);
}


quadrangle::quadrangle()
{
    n = 4;
    el = new double[n];
    с = new point[n];
    for (int i = 0; i < n; ++i)
    {
        srand(time(NULL) + i);
        с[i].x = rand() % 60;
        srand(time(NULL) + i + 10);
        с[i].y = rand() % 60;
    }
    form_edges();
}


quadrangle::quadrangle(point vert[])
{
    n = 4;
    el = new double[n];
    с = new point[n];
    for (int i = 0; i < n; ++i)
    {
        с[i] = vert[i];
    }
    form_edges();
}


quadrangle::~quadrangle()
{
    delete[]el;
    delete[]с;
}


void quadrangle::check_trapeze()
{
    
    triangle_inequality() && abs(abs(distance(с[2], с[1], с[3], с[0])) - el[1] * el[3]) ||
    triangle_inequality() && (abs(abs(distance(с[0], с[1], с[3], с[2])) - el[0] * el[2]) <= eps) <= eps ?
    std::cout << "Quadrangle is trapeze" : std::cout << "Quadrangle is not trapeze";
    
}




bool quadrangle::check_parallelogram()
{
    if (triangle_inequality())
    {
        double sc1 = distance(с[2], с[1], с[3], с[0]) - el[1] * el[3];
        double sc2 = distance(с[0], с[1], с[3], с[2]) - el[0] * el[2];
        if (abs(sc1 <= eps) && abs(sc2 <= eps)) return true;
    }
    return false;
}


void quadrangle::printP()
{
    check_parallelogram() ? std::cout << "Quadrangle is parallelogram" : std::cout << "Quadrangle is not parallelogram";
}



void quadrangle::check_rhombus()
{
    check_parallelogram() && abs(el[0] - el[1]) <= eps ? std::cout << "Quadrangle is rohmbus" : std::cout << "Quadrangle is not rohmbus";
}



void quadrangle::check_rectangle()
{
    check_parallelogram() && right_angle(с[0], с[1], с[2]) ? std::cout<< "Quadrangle is rectangle" :  std::cout<< "Quadrangle is not rectangle";
}



void quadrangle::check_square() // parallelogram and rombus
{
    check_parallelogram() && abs(el[0] - el[1]) <= eps && right_angle(с[0], с[1], с[2]) ? std::cout << "Quadrangle is square " :
    std::cout<< "Quadrangle is not square";
}



double quadrangle::area()
{
    double square_rectangle = el[0] * el[1];
    double l = length(с[0], с[2]);
    if (check_parallelogram() && abs(el[0] - el[1]) <= eps && right_angle(с[0], с[1], с[2]))
    std::cout << "Area of quadrangle is " << square_rectangle << std::endl;
    return square_rectangle;   // square or rectangle
   
   if((check_parallelogram() && abs(el[0] - el[1]) <= eps) || check_parallelogram())//rombus and parallelogram
    {
        
        double pa1 = (l + el[0] + el[1]) / 2;
        double paral_romb = 2 * sqrt(pa1*(pa1 - el[0])*(pa1 - el[1])*(pa1 - l));
        std::cout << "Area of quadrangle is " << paral_romb << std::endl;
    }
    else
    {
        double p2 = (l + el[0] + el[1]) / 2;
        double p3 = (l + el[2] + el[3]) / 2;
        double m = sqrt(p2*(p2 - el[0])*(p2 - el[1])*(p2 - l));
        double m1 = sqrt(p3*(p3 - el[2])*(p3 - el[3])*(p3 - l));
        double area = m + m1;
        std::cout << "Area is " << area << std::endl;
    }
    return 1;
}


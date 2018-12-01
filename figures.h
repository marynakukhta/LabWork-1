
#ifndef figures_h
#define figures_h


#endif /* figures_h */


#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct point
{
    int x, y;
};

class figures
{
protected:
    int n; //количество вершин
    point *с; // координаты вершин
    double *el; //длинна ребра
    const double eps = 0.01;
public:
    friend double length(point a, point b); //длинна
    bool triangle_inequality();//неравенство треугольника
    double perimeter();//периметр
    bool right_angle(point a, point b, point c);//прямой угол
    void zero();
    friend double distance(point a, point b, point c, point d);//длинна отрезка
    void print();
};


inline double length(point a, point b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}


bool figures::triangle_inequality()
{
    double length = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j) length += el[j];
        for (int j = i + 1; j < n; ++j)
        {
            length += el[j];
            if (с[i].x == с[j].x && с[i].y == с[j].y)
            {
                zero();
                return false;
            }
        }
        if (length <= el[i])
        {
            zero();
            return false;
        }
    }
 
    return true;
}


double distance(point a, point b, point c, point d)
{
    return ((a.x - b.x)*(c.x - d.x) + (a.y - b.y)*(c.y - d.y));
}


void figures::zero()
{
    for (int i = 0; i < n; ++i)
    {
        el[i] = 0;
        с[i].x = с[i].y = 0;
    }
}

double figures::perimeter()
{
    double p = 0;
    for (int i = 0; i < n; ++i)
    {
        p += el[i];
    }
    std::cout << "Perimeter is " << p;
    return p;
}


inline bool figures::right_angle(point a, point b, point c)
{
  if (abs(distance(a, b, c, b) <= eps)) return true;
  return false;
 
}


void figures::print()
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << "X: " << с[i].x << " Y: " << с[i].y << std::endl;
    }
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Length of edge: " << el[i] << std::endl; 
    }
}

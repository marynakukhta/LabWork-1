
#include "figures.h"
#include "pentagon.h"
#include "quadrangle.h"
#include "triangle.h"
#include "matrixGraph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <ctime>


int main()
{

    int d1[] = { 10, 20, 30, 40, 50 };

    
    matrixGraph<int> gr("File1.bin", d1);
    gr.print();
    bool connect = gr.connected();
    if (connect) std::cout << "Graph is connected" << std::endl;
    else std::cout << "Graph is not connected" << std::endl;
   
    int dist = gr.Dijkstra(5, 3 );
    std::cout << "Distance is : " << dist << std::endl;
    
    std::cout << std::endl << "~~~~~~~~~~~~~~~" << std::endl;
    
    
    point tr[3] = { { 3,1 },{ 3,6 },{ 6,1 } };
    triangle t;
    std::cout << "Triangle" << std::endl;
    t.print();
    
    t.check_right();
    std::cout << "" << std::endl;
    
    t.check_isoscelesT();
    std::cout << "" << std::endl;
    
    t.check_equilateral();
    std::cout << "" << std::endl;
    
    t.perimeter();
    std::cout << "" << std::endl;
    
    t.area();
    std::cout << "" << std::endl;
    
    
    
    point qua[] = { { 3,7 },{ 5,9 },{ 9,5 },{ 3, 7 } };
    quadrangle q;
    std::cout << "Quadrangle" << std::endl;
    q.print();
    
    q.check_trapeze();
    std::cout << "" << std::endl;
    
    q.printP();
    std::cout << "" << std::endl;
    
    q.check_rhombus();
    std::cout << "" << std::endl;
    
    q.check_rectangle();
    std::cout << "" << std::endl;
    
    q.check_square();
    std::cout << "" << std::endl;
    
    q.perimeter();
    std::cout << "" << std::endl;
    
    q.area();
    std::cout << "" << std::endl;
    
    
    
    pentagon p;
    std::cout << "Pentagon" << std::endl;
    p.print();

    p.right_angle();
    std::cout << "" << std::endl;
    
    p.perimeter();
    std::cout << "" << std::endl;
    
    p.area();
    std::cout << "" << std::endl;
    
    system("pause");
    return 0;
}

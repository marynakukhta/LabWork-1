#ifndef triangle_h
#define triangle_h

#endif /* triangle_h */

class triangle :public figures
{
public:
    triangle();
    triangle(point vert[]);
    ~triangle();
    double area();//площадь
    void form_edges();//формирование ребер
    void check_right();//прямоугольный
    void check_equilateral(); //равнобедренный
    void check_isoscelesT(); //равносторонний

};


void triangle::form_edges()
{
    el[0] = length(с[0], с[1]);
    el[1] = length(с[1], с[2]);
    el[2] = length(с[2], с[0]);
}

triangle::triangle()
{
    n = 3;//количество вершин
    el = new double[n];//длинна ребра
    с = new point[n];//// координаты вершин
    for (int i = 0; i < n; ++i)
    {
        srand(i + time(NULL));
        с[i].x = rand() % 10;
        srand(time(NULL) + i + 10);
        с[i].y = rand() % 10;
    }
    form_edges();
}

triangle::triangle(point vert[])
{
    n = 3;
    el = new double[n];
    с = new point[n];
    for (int i = 0; i < n; ++i)
    {
        с[i] = vert[i];
    }
    form_edges();
}


void triangle::check_right()
{
    triangle_inequality() && right_angle(с[0], с[1], с[2]) || right_angle(с[2], с[0], с[1]) || figures::right_angle(с[1], с[2], с[2]) ? std::cout << "Triangle is right" : std::cout << "Triangle is not right";
}


void triangle::check_isoscelesT()
{
    triangle_inequality() && (abs(el[0] - el[1]) <= eps || abs(el[0] - el[2]) <= eps || abs(el[1] - el[2]) <= eps) ?  std::cout << "Triangle is isosceles" : std::cout << "Triangle is not isosceles";
}


void triangle::check_equilateral()
{
    
    (triangle_inequality() && abs(el[0] - el[1]) <= eps && abs(el[0] - el[2]) <= eps) ? std::cout << "Triangle is Equilatetal" :
    std::cout << "Triangle is not equilatetal";
    
}


double triangle::area()
{
    double p = 0;
    for (int i = 0; i < n; ++i)
    {
        p += el[i];
    }
    double result = sqrt(p*(p - el[0]) * (p - el[1]) * (p - el[2]));
    std::cout << "Area is " << result << std::endl;
        return result;
    }
    
    
triangle::~triangle()
{
    delete[]el;
    delete[]с;
}

#ifndef ArrGraph_h
#define ArrGraph_h

#endif /* ArrGraph_h */
#define F(i) for(int i=0; i<vNum; ++i)
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

template <typename T>class matrixGraph
{
private:
    int **matrix;
    T *data;
    int vNum;
    
public:
   
    void dfs(int, bool *, int *);
    bool connected(); //проверка графа на связность
    matrixGraph(std::string, T*); //конструктор
    ~matrixGraph(); //деструктор
    void print();
    int Dijkstra( int , int );//находит расстояние
};


 template <typename T>
 bool matrixGraph<T>::connected()
{
    bool *used = new bool[vNum];//массив пометок
    int *cc = new int[vNum];//// сс[v] = номер компоненты, к которой принадлежит v
    int ccNum = 0; //// количество компонент
    for (int v = 0; v < vNum; v++)
    {
       if(!used[v])//если текущая не помечена
       {
           ccNum ++;// значит мы нашли компоненту связности
           dfs(v,used,cc);// запускаем на ней DFS
           }
        }
    return true;
}

template <typename T>
int matrixGraph<T>::Dijkstra( int vNum, int st)
{
    //Алгоритм Дейкстры - находит расстояние вершины номер st
    //графа размерностью vNum   до всех остальных
    //Вернет массив расстояний
    int *distance, count, index, i, u;
    bool *visited;
    distance = new int[vNum];
    visited = new bool[vNum];//флаг
    for (i = 0; i<vNum; i++) { distance[i] = std::numeric_limits<int>::max(); visited[i] = false; }
    distance[st] = 0;//расстояние для начальной вершины полагается равным нулю
    for (count = 0; count<vNum - 1; count++) {
        int min = std::numeric_limits<int>::max();// а все остальные расстояния заполняются большим положительным числом
      
        for (i = 0; i<vNum; i++)
            if (!visited[i] && distance[i] <= min) { min = distance[i]; index = i; } //На каждом шаге цикла мы ищем вершину i с минимальным расстоянием и флагом равным нулю
        u = index;
        visited[u] = true; //Затем мы устанавливаем в ней флаг в 1 и проверяем все соседние с ней вершины  u
        for (i = 0; i<vNum; i++)
            if (!visited[i] && matrix[u][i] && distance[u] != std::numeric_limits<int>::max() && //Если в u расстояние больше, чем сумма расстояния до текущей вершины и длины ребра
                distance[u] + matrix[u][i]<distance[i])
                distance[i] = distance[u] + matrix[u][i];//Каждой из рассмотренных вершин назначим длинну пути  равную сумме длинны u и длинны пути из u в рассматриваемую вершину, но только в том случае, если полученная сумма будет меньше предыдущего значения длинны. Если же сумма не будет меньше, то оставляем предыдущую дистанцию без изменений.
        //Цикл завершается, когда флаги всех вершин становятся равны 1
    }
    return *distance;
}


template<typename T>
matrixGraph<T>:: ~matrixGraph()
{
    F(i)
    {
        delete matrix[i];
    }
    delete[] matrix;
}


template <typename T>
void matrixGraph<T>::dfs(int v, bool *used, int *cc)
{
    used[v] = true;
    cc[v] = vNum;// ставим текущей вершине в соответствие номер компоненты
    F(i)
    {
      if (!used[i] && matrix[v][i]) //// если i не помечена и смежна с v
      {
          dfs(i, used, cc);
      }
}
}



template <typename T>
matrixGraph<T>::matrixGraph(std::string fname, T* dat)
{
    std::ifstream in(fname, std::ios::binary);
    in.read((char*)&vNum, sizeof(int));
    data = new T[vNum];
    matrix = new int*[vNum];
    F(i)
    {
        matrix[i] = new int[vNum];
        data[i] = dat[i];
    }
    int k = 0;
    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            in.read((char*)&k, sizeof(int));
            matrix[i][j] = k;
        }
    }
    in.close();
}

template<typename T>
void matrixGraph<T>::print()
{
    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    F(i)
    {
        std::cout << "Data: ";
        std::cout << data[i] << std::endl;
    }
    
}

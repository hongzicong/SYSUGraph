//
// Created by user on 12/27/17.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#include <iostream>
#include <climits>
#include <string>

#define MAX_VERTEX 100

class graph {

private:
    int num;
    int distance[MAX_VERTEX];
    bool isVisit[MAX_VERTEX];
    std::string vertex[MAX_VERTEX];
    int map[MAX_VERTEX][MAX_VERTEX];
public:
    graph();
    bool Dijkstra(int a,int b);
    void clearDistance();
    void clearVisit();
    int findMinDistance();
    void setData(std::ifstream &file);
};


#endif //UNTITLED_GRAPH_H

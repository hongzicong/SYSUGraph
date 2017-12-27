//
// Created by user on 12/27/17.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include <queue>

#define MAX_VERTEX 100

class graph {

private:
    int num;
    int distance[MAX_VERTEX];
    bool isVisit[MAX_VERTEX];
    std::string vertex[MAX_VERTEX];
    std::string detail[MAX_VERTEX];
    int map[MAX_VERTEX][MAX_VERTEX];
    std::queue<int> route;
    void swap(int &a,int &b);
public:
    graph();
    bool Dijkstra(std::string &a,std::string &b);
    void clearDistance();
    void clearVisit();
    int findMinDistance();
    void setData(std::ifstream &file);
    int getID(std::string &name);
    void getNode();
    void getMap();
    void printRoute();
};


#endif //UNTITLED_GRAPH_H

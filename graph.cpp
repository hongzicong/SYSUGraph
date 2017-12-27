//
// Created by user on 12/27/17.
//

#include "graph.h"

graph::graph() {
    clearVisit();
    clearDistance();
    for(int i=0;i<MAX_VERTEX;++i){
        for(int j=0;j<MAX_VERTEX;++j){
            map[i][j]=0;
        }
    }
}

bool graph::Dijkstra(std::string &str_a, std::string &str_b) {
    int a=getID(str_a);
    int b=getID(str_b);
    clearDistance();
    distance[a]=0;
    isVisit[a]=true;
    do{
        for(int i=0;i<num;++i){
            if(map[a][i]!=0&&isVisit[i]==false){
                if(distance[i]>distance[a]+map[a][i]){
                    distance[i]=distance[a]+map[a][i];
                }
            }
        }
    a=findMinDistance(); }while(a!=-1&&a!=b);
    if(a==-1){
        return false;
    }
    else{
        return true;
    }
}

int graph::findMinDistance(){
    int minDistance=INT_MAX;
    int index=-1;
    for(int i=0;i<num;++i){
        if(isVisit[i]==false){
            if(distance[i]<minDistance){
                minDistance=distance[i];
                index=i;
            }
        }
    }
    if(index!=-1){
        isVisit[index]=true;
    }
    return index;
}

void graph::setData(std::ifstream &file){
}

void graph::clearDistance() {
    for(int i=0;i<MAX_VERTEX;++i){
        distance[i]=INT_MAX;
    }
}

void graph::clearVisit(){
    for(int i=0;i<MAX_VERTEX;++i){
        isVisit[i]=false;
    }
}

int graph::getID(std::string &name) {
    for(int i=0;i<MAX_VERTEX;++i){
        if(name==vertex[i]){}
        return i;
    }
    return -1;
}
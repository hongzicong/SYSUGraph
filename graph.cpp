//
// Created by user on 12/27/17.
//

#include "graph.h"

graph::graph() {
    clearVisit();
    clearDistance();
    for (int i = 0; i < MAX_VERTEX; ++i) {
        for (int j = 0; j < MAX_VERTEX; ++j) {
            map[i][j] = 0;
        }
        canCar[i]=false;
    }
}

bool graph::Dijkstra_car(std::string &str_a,std::string &str_b){
    while (!route.empty()) {
        route.pop();
    }
    int a = getID(str_a);
    int b = getID(str_b);
    clearDistance();
    distance[a] = 0;
    isVisit[a] = true;
    if(canCar[a]==false){
        std::cout<<"1"<<std::endl;
        return false;
    }
    do {
        route.push(a);
        for (int i = 0; i < num; ++i) {
            if (map[a][i] != 0 && isVisit[i] == false &&canCar[i]==true) {
                if (distance[i] > distance[a] + map[a][i]) {
                    distance[i] = distance[a] + map[a][i];
                }
            }
        }
        a = findMinDistance_car();
    } while (a != -1 && a != b);
    if (a == -1) {
        return false;
    } else {
        route.push(a);
        return true;
    }
}

bool graph::Dijkstra(std::string &str_a, std::string &str_b) {
    while (!route.empty()) {
        route.pop();
    }
    int a = getID(str_a);
    int b = getID(str_b);
    clearDistance();
    distance[a] = 0;
    isVisit[a] = true;
    do {
        route.push(a);
        for (int i = 0; i < num; ++i) {
            if (map[a][i] != 0 && isVisit[i] == false) {
                if (distance[i] > distance[a] + map[a][i]) {
                    distance[i] = distance[a] + map[a][i];
                }
            }
        }
        a = findMinDistance();
    } while (a != -1 && a != b);
    if (a == -1) {
        return false;
    } else {
        route.push(a);
        return true;
    }
}

int graph::findMinDistance() {
    int minDistance = INT_MAX;
    int index = -1;
    for (int i = 0; i < num; ++i) {
        if (isVisit[i] == false) {
            if (distance[i] < minDistance) {
                minDistance = distance[i];
                index = i;
            }
        }
    }
    if (index != -1) {
        isVisit[index] = true;
    }
    return index;
}

int graph::findMinDistance_car() {
    int minDistance = INT_MAX;
    int index = -1;
    for (int i = 0; i < num; ++i) {
        if (isVisit[i] == false&&canCar[i]==true) {
            if (distance[i] < minDistance) {
                minDistance = distance[i];
                index = i;
            }
        }
    }
    if (index != -1) {
        isVisit[index] = true;
    }
    return index;
}

void graph::setData(std::ifstream &file_1,std::ifstream &file_2) {
    int count;
    int id;
    file_1 >> num;
    file_2 >> count;
    int a, b;
    int dist;
    std::string place;
    for (int i = 0; i < count; ++i) {
        file_2 >> a >> b >> dist;
        map[a-1][b-1] = dist;
        map[b-1][a-1] = dist;
    }
    for (int i = 0; i < num; ++i) {
        file_1>>id;
        file_1 >> place;
        vertex[i]=place;
        file_1>>place;
        detail[i] = place;
        file_1>>id;
        canCar[i]=id;
    }
}

void graph::clearDistance() {
    for (int i = 0; i < MAX_VERTEX; ++i) {
        distance[i] = INT_MAX;
    }
}

void graph::clearVisit() {
    for (int i = 0; i < MAX_VERTEX; ++i) {
        isVisit[i] = false;
    }
}

int graph::getID(std::string &name) {
    for (int i = 0; i < MAX_VERTEX; ++i) {
        if (name == vertex[i]) {
            return i;
        }
    }
    return -1;
}

void graph::getNode() {
    for (int i = 0; i < num; ++i) {
        std::cout << "[" << i << "] " << vertex[i] << " " << detail[i] << std::endl;
        std::cout<<std::endl;
    }
}

void graph::getMap() {

}

void graph::printRoute() {
    int a, b;
    a = route.front();
    route.pop();
    std::cout << vertex[a];
    while (!route.empty()) {
        b=route.front();
        std::cout << "---(" << map[a][b] <<"min)"<< "--->";
        std::cout << vertex[b];
        route.pop();
        swap(a,b);
    }
    std::cout<<std::endl;
}

void graph::printCarRoute() {
    int a, b;
    a = route.front();
    route.pop();
    std::cout << vertex[a];
    while (!route.empty()) {
        b=route.front();
        std::cout << "---(" << map[a][b]/5 <<"min)"<< "--->";
        std::cout << vertex[b];
        route.pop();
        swap(a,b);
    }
    std::cout<<std::endl;
}

void graph::swap(int &a, int &b) {
    int temp=a;
    a=b;
    b=temp;
}
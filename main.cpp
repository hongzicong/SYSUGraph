#include <iostream>
#include <fstream>
#include "graph.h"

int main()
{
    // std::cout << "Hello, World!" << std::endl;
    bool quit = false;
    while (!quit)
    {
        std::cout << "=================================================" << std::endl;
        std::cout << "=\t\t\t\t\t请选择操作\t\t\t\t\t=" << std::endl;
        std::cout << "=================================================" << std::endl;
        std::cout << "= m. 给出地图\t\t\t\t\t\t\t\t\t\t=" << std::endl;
        std::cout << "= n. 给出每个节点信息\t\t\t\t\t\t\t\t=" << std::endl;
        std::cout << "= s. 两点间最短路径\t\t\t\t\t\t\t\t=" << std::endl;
        std::cout << "= q. 退出此程序\t\t\t\t\t\t\t\t\t=" << std::endl;
        std::cout << "=================================================" << std::endl;

        char choice;
        std::cin >> choice;
        choice = tolower(choice);
        graph newgraph;
        std::ifstream in("data");
        newgraph.setData(in);
        switch (choice)
        {
            case 'm':
                newgraph.getMap();
                break;
            case 'n':
                newgraph.getNode();
                break;
            case 's':
                std::string s1, s2;
                std::cin >> s1 >> s2;
                if (newgraph.Dijkstra(s1, s2));
                else
                {
                    std::cout << "依据给出的信息，不存在可能的最短路径！" << std::endl;
                }
                break;
            case 'q':
                quit = true;
                break;
            default:
                std::cout << "Invalid Command!" << std::endl;
                break;
        }
        std::system("clear");
    }
    return 0;
}
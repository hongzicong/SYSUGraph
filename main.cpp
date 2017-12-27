#include <iostream>
#include <fstream>
#include "graph.h"

int main()
{
    bool quit = false;
    char choice;
    std::string s1, s2;
    graph SYSUEastCampusGraph;
    std::ifstream in_1("C:\\Users\\DELL-PC\\CLionProjects\\SYSUGraph\\NodeData.txt");
    //std::ifstream in_2("C:\\Users\\DELL-PC\\CLionProjects\\SYSUGraph\\MapData.txt");
    std::string temp;
    in_1>>temp;
    std::cout<<temp<<std::endl;
    //SYSUEastCampusGraph.setData(in_1,in_2);

    while (!quit)
    {
        std::cout << "=================================================" << std::endl;
        std::cout << "=\t\t请选择操作\t\t\t=" << std::endl;
        std::cout << "=================================================" << std::endl;
        std::cout << "= m. 给出地图\t\t\t\t\t=" << std::endl;
        std::cout << "= n. 给出每个节点信息\t\t\t\t=" << std::endl;
        std::cout << "= s. 两点间最短路径\t\t\t\t=" << std::endl;
        std::cout << "= q. 退出此程序\t\t\t\t\t=" << std::endl;
        std::cout << "=================================================" << std::endl;

        std::cin >> choice;
        choice = tolower(choice);
        switch (choice)
        {
            case 'm':
                SYSUEastCampusGraph.getMap();
                break;
            case 'n':
                SYSUEastCampusGraph.getNode();
                break;
            case 's':
                std::cout<<"请写出两个地点之间的名称（空格间隔）：";
                std::cin >> s1 >> s2;
                if (SYSUEastCampusGraph.Dijkstra(s1, s2))
                {
                    std::cout << "依据给出的信息，给出最短路径如下：" << std::endl;
                    SYSUEastCampusGraph.printRoute();
                }
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
        std::system( "PAUSE ");
        std::system("cls");
    }
    return 0;
}
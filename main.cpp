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
        std::cout << "=\t\t��ѡ�����\t\t\t=" << std::endl;
        std::cout << "=================================================" << std::endl;
        std::cout << "= m. ������ͼ\t\t\t\t\t=" << std::endl;
        std::cout << "= n. ����ÿ���ڵ���Ϣ\t\t\t\t=" << std::endl;
        std::cout << "= s. ��������·��\t\t\t\t=" << std::endl;
        std::cout << "= q. �˳��˳���\t\t\t\t\t=" << std::endl;
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
                std::cout<<"��д�������ص�֮������ƣ��ո�������";
                std::cin >> s1 >> s2;
                if (SYSUEastCampusGraph.Dijkstra(s1, s2))
                {
                    std::cout << "���ݸ�������Ϣ���������·�����£�" << std::endl;
                    SYSUEastCampusGraph.printRoute();
                }
                else
                {
                    std::cout << "���ݸ�������Ϣ�������ڿ��ܵ����·����" << std::endl;
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
#include <iostream>

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
        switch (choice)
        {
            case 'm':
            case 'n':
            case 's':
                break;
            case 'q':
                quit = true;
                break;
            default:
                std::cout << "Invalid Command!" << std::endl;
                break;
        }
    }
    std::system("clear");
    return 0;
}
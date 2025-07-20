#include <iostream>

int main(int argc, char * argv[])
{
    std::cout << "Cantidad de argumentos: " << argc << "\n";
    std::cout << "Argumentos: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << " ";
    return 0;
}
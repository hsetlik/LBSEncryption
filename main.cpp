#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "You have entered " << argc << " arguments\n";
    for (int i = 0; i < argc; i++)
    {
        std::cout << "Argument " << i << " has length " << strlen(argv[i]) << ":\n";
        std::cout << argv[i] << "\n";
    }

    return 0;
}
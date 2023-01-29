#include <iostream>
#include "LBSEncryption.h"

int main(int argc, char** argv)
{
    std::cout << "You have entered " << argc << " arguments\n";
    std::string source = "null";
    std::string dest = "null";
    std::string key = "null";
    std::string key1 = "null";
    std::string key2 = "null";
    for (int i = 0; i < (argc - 1); i++)
    {
        std::cout << "Argument " << i << " is " << argv[i] << "\n";
        if (strcmp(argv[i], "source") == 0)
            source = argv[i + 1];
        else if (strcmp(argv[i], "dest") == 0)
            dest = argv[i + 1];
        else if (strcmp(argv[i], "key") == 0)
            key = argv[i + 1];
        else if (strcmp(argv[i], "key1") == 0)
            key1 = argv[i + 1];
        else if (strcmp(argv[i], "key2") == 0)
            key2 = argv[i + 1];
    }
    std::cout << "dest is: " << dest << "\n";
    std::cout << "source is: " << source << "\n";
    if (key1 != "null" && key2 != "null")
    {
        std::cout << "Two-key mode\n";
        LBSDoubleKey lbs(key1, key2);
        lbs.encryptFile(source, dest);   
    }
    else
    {
        std::cout << "One-key mode\n";
        LBSSingleKey lbs(key);
        lbs.encryptFile(source, dest);
    }

    return 0;
}
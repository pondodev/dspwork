#include <iostream>
#include <fstream>
#include "CharacterCounter.h"

int main ()
{
    CharacterCounter c;
    unsigned char input;
    std::ifstream inputFile("test");

    while (inputFile >> input)
    {
        c.Count(input);
    }

    std::cout << c;

    return 0;
}

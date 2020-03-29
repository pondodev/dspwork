#include <iostream>
#include "CharacterCounter.h"

CharacterCounter::CharacterCounter()
{
    totalCharCount = 0;
    
    for (int i = 0; i < 256; i++)
    {
        charCounts[i] = 0;
    }
}

void CharacterCounter::Count(unsigned char character)
{
    // increment the total num of chars and then the individual char in the array
    totalCharCount++;
    charCounts[(int)character]++;
}

std::ostream &operator<<(std::ostream &os, const CharacterCounter &c)
{
    // show total
    os << "total: " << c.totalCharCount << std::endl;

    // show all individual character counts
    for (int i = 33; i < 127; i++)
    {
        os << (char)i << ": " << c.charCounts[i] << std::endl;
    }
    
    return os;
}

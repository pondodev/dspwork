#include "BubbleSort.h"

BubbleSort::BubbleSort( int aArrayOfNumbers[], unsigned int aArraySize ) : ArraySorter(aArrayOfNumbers, aArraySize) { }

// code for bubble sort from https://www.geeksforgeeks.org/bubble-sort/
void BubbleSort::sort( std::ostream& aOStream )
{
    for (int i = 0; i < getRange() - 1; i ++)
    {
        for (int j = 0; j < getRange() - 1 - i; j++)
        {
            if (at(j) > at(j + 1)) swapElements(j, j + 1);
        }

        // just make sure we're always showing our progress
        stepCompleted(aOStream);
    }
}

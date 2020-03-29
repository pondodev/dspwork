#include "InsertionSort.h"

InsertionSort::InsertionSort( int aArrayOfNumbers[], unsigned int aArraySize ) : ArraySorter(aArrayOfNumbers, aArraySize) { }

// code for insertion sort from https://en.wikipedia.org/wiki/Insertion_sort#Algorithm
void InsertionSort::sort( std::ostream& aOStream )
{
    for (int i = 1; i < getRange(); i++)
    {
        int j = i;
        while (j > 0 && at(j - 1) > at(j))
        {
            swapElements(j, j - 1);
            j--;
        }

        // print out our progress
        stepCompleted(aOStream);
    }
}

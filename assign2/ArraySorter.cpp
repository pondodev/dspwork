#include "ArraySorter.h"
#include <stdexcept>
#include <iostream>

using namespace std;

ArraySorter::ArraySorter( const int aArrayOfNumbers[], unsigned int aArraySize )
{
    // copy array into sorter
    fArrayOfNumbers = new int[aArraySize];

    for ( unsigned int i = 0; i < aArraySize; i++ )
    {
        fArrayOfNumbers[i] = aArrayOfNumbers[i];
    }
    fArraySize = aArraySize;
}

ArraySorter::~ArraySorter()
{
    // delete memory associated with array
    delete [] fArrayOfNumbers;
}

void ArraySorter::stepCompleted( std::ostream& aOStream )
{
    aOStream << "state: [" << fArrayOfNumbers[0];

    for (int i = 1; i < getRange(); i++)
    {
        aOStream << ", " << fArrayOfNumbers[i];
    }

    aOStream << "]" << endl;
}

void ArraySorter::swapElements( unsigned int aSourcIndex, unsigned int aTargetIndex )
{
    int temp = fArrayOfNumbers[aSourcIndex];
    fArrayOfNumbers[aSourcIndex] = fArrayOfNumbers[aTargetIndex];
    fArrayOfNumbers[aTargetIndex] = temp;
}

const unsigned int ArraySorter::at( unsigned int aIndex ) const
{
    // note: aIndex >= getRange() because the method returns the size, not the max index which is size - 1
    // also don't need to check for < 0 since aIndex is unsigned
    if (aIndex >= getRange()) // if out of bounds...
    {
        //...throw error...
        throw range_error("index is out of range");
    }

    //...otherwise we can return the int at aIndex
    return fArrayOfNumbers[aIndex];
}

const unsigned int ArraySorter::getRange() const
{
    return fArraySize;
}

void ArraySorter::sort( std::ostream& aOStream )
{
    stepCompleted(aOStream);
}

std::ostream& operator<<( std::ostream& aOStream, const ArraySorter& aObject )
{
    aOStream << "[" << aObject.at(0);
    
    for (int i = 1; i < aObject.getRange(); i++)
    {
        aOStream << ", " << aObject.at(i);
    }

    aOStream << "]" << endl;

    return aOStream;
}

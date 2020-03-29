#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"
#include <stdexcept>

FibonacciSequence::FibonacciSequence( unsigned long aLimit )
{
    fPrevious = 0;
    fCurrent = 1;
    fPosition = 1;
    fLimit = aLimit;
}

const unsigned long& FibonacciSequence::current() const
{
    return fCurrent;
}

void FibonacciSequence::advance()
{
    if (fPosition > fLimit && fLimit != 0) throw std::range_error("out of bounds");

    unsigned long next = fCurrent + fPrevious;
    fPrevious = fCurrent;
    fCurrent = next;
    fPosition++;
}

const unsigned long& FibonacciSequence::getLimit() const
{
    return fLimit;
}

FibonacciSequenceIterator FibonacciSequence::begin()
{
    fPrevious = 0;
    fCurrent = 1;
    fPosition = 1;
    FibonacciSequenceIterator result(this, fPosition);

    return result;
}

FibonacciSequenceIterator FibonacciSequence::end()
{
    FibonacciSequenceIterator result(this, fLimit + 1);

    return result;
}
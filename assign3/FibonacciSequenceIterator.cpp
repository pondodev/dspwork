#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"

FibonacciSequenceIterator::FibonacciSequenceIterator( FibonacciSequence* aPtrToSequenceObject, unsigned long aStart )
{
    fPtrToSequenceObject = aPtrToSequenceObject;
    fIndex = aStart;
}

const unsigned long& FibonacciSequenceIterator::operator*() const
{
    return fPtrToSequenceObject->current();
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++()
{
    fPtrToSequenceObject->advance();
    fIndex++;
    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++( int )
{
    FibonacciSequenceIterator temp = *this;
    ++(*this);

    return temp;
}

bool FibonacciSequenceIterator::operator==( const FibonacciSequenceIterator& aOther ) const
{
    return fIndex == aOther.fIndex && fPtrToSequenceObject == aOther.fPtrToSequenceObject;
}

bool FibonacciSequenceIterator::operator!=( const FibonacciSequenceIterator& aOther ) const
{
    return !((*this) == aOther);
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const
{
    return fPtrToSequenceObject->begin();
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
    return fPtrToSequenceObject->end();
}
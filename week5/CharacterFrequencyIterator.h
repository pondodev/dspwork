// COS30008, Tutorial 5, 2019

#pragma once

#include "CharacterMap.h"
#include "CharacterCounter.h"

class CharacterFrequencyIterator
{
    private:
        CharacterMap fMap[256];     // character frequency maps, automatically initialized
        int fIndex;                 // position of indexer, requires initialization
        void advanceIndex();        // advance index to the next non-zero frequency

    public:
        // constructor: takes a read-only reference to character counter and
        //                    a Boolean flag to indicate whether or not to sort
        // iterator positioned on first non-zero character map, or 257th
        CharacterFrequencyIterator( const CharacterCounter& aCounter, bool 
        aSort = false );

        // sort method: Bubble Sort, decreasing order (push highest to left)
        void sort();

        // forward iterator interface
        const CharacterMap& operator*() const;              // returns current frequency map

        CharacterFrequencyIterator& operator++();           // prefix increment
        CharacterFrequencyIterator operator++( int );       // postfix increment

        bool operator==( const CharacterFrequencyIterator& aOther ) const;
        bool operator!=( const CharacterFrequencyIterator& aOther) const;

        CharacterFrequencyIterator begin() const;           // return iterator positioned at first non-zero
        CharacterFrequencyIterator end() const;             // return iterator positioned at 256
};

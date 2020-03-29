// COS30008, Tutorial 5, 2019

#pragma once

#include <iostream>

class CharacterCounter
{
    private:
        int fTotalNumberOfCharacters;
        int fCharacterCounts[256];

    public:
        CharacterCounter();

        void count( unsigned char aCharacter );        // We count all 256 byte values
        // new in tutorial 5: indexer
        const int operator[]( unsigned char aCharacter ) const;
        friend std::ostream& operator<<( std::ostream& aOStream,
        const CharacterCounter& aCharacterCounter );
};

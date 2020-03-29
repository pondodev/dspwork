// COS30008, Tutorial 4, 2019
#pragma once
#include <ostream>
class CaesarCipher
{
    private:
        int fOffset;
        unsigned int fCharacterFrequenciesBefore[26];
        unsigned int fCharacterFrequenciesAfter[26];

    public:
        CaesarCipher( int aOffset = 4 );

        // indexer to map clear characters to encoded characters
        char operator[]( char aCharacter );
        friend std::ostream& operator<<( std::ostream& aOStream, const 
        CaesarCipher& aObject );
};

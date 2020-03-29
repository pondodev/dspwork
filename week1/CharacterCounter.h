#pragma once

class CharacterCounter
{
    private:
        int totalCharCount;
        int charCounts[256];

    public:
        CharacterCounter();

        void Count(unsigned char character);
        friend std::ostream &operator<<(std::ostream &_ostream, const CharacterCounter &_CharacterCounter);
};

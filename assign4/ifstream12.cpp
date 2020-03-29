#include "ifstream12.h"

void ifstream12::init()
{
    for (int i = 0; i < fBufferSize; i++)
        fBuffer[i] = 0;

    fByteIndex = 0;
    fBitIndex = 7;
}

void ifstream12::reload()
{
    init();
    fIStream.read((char*)fBuffer, fBufferSize);

    fBytesAvailable = fIStream.gcount();
}

int ifstream12::readBit()
{
    if (fBytesAvailable == 0) reload();
    if (eof()) return -1;

    int result = (fBuffer[fByteIndex] & (1 << fBitIndex)) != 0;
    fBitIndex--;
    if (fBitIndex == -1)
    {
        fBitIndex = 7;
        fByteIndex++;
        fBytesAvailable--;
    }

    return result;
}

ifstream12::ifstream12(const char* aFileName, unsigned int aBufferSize)
{
    fBufferSize = aBufferSize;
    fBuffer = new unsigned char[fBufferSize];

    init();

    open(aFileName);
}

ifstream12::~ifstream12()
{
    close();

    delete [] fBuffer;
}

void ifstream12::open(const char* aFileName)
{
    if (aFileName)
        fIStream.open(aFileName, std::ifstream::binary);
}

void ifstream12::close()
{
    fIStream.close();
}

bool ifstream12::isOpen() const
{
    return fIStream.is_open();
}

bool ifstream12::good() const
{
    return fIStream.good();
}

bool ifstream12::eof() const
{
    return fBytesAvailable == 0 && fIStream.eof();
}

ifstream12& ifstream12::operator>>(int & a12BitValue)
{
    a12BitValue = 0;
    for (int i = 1; i <= 12; i++)
    {
        int lBit = readBit();
        if (lBit == -1)
            break;

        if (lBit == 1)
            a12BitValue = (1 << (i - 1)) + a12BitValue;
    }

    return *this;
}

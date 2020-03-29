
// COS30008, Tutorial 6, 2019

#pragma once

#include <fstream>

class ofstream12
{
private:
	std::ofstream fOStream;

    unsigned char *fBuffer;     // output buffer
    unsigned int fBufferSize;   // output buffer size
    
	int fByteIndex;             // current byte index
	int fBitIndex;              // current bit index

	void init();		        // initialize data members
	void completeWriteBit();    // complete write
	void writeBit0();           // write 0
	void writeBit1();           // write 1

public:
    // using C++11's nullptr
	ofstream12( const char *aFileName = nullptr, unsigned int aBufferSize = 128 );
	~ofstream12();

	void open( const char *aFileName );
	void close();

	bool good() const;
    bool isOpen() const;
    
	void flush();

	ofstream12& operator<<( int aValue );
};

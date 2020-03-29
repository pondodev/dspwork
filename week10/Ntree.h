
// COS30008, Tutorial 10, 2019

#pragma once

#include <stdexcept>

template<class T, int N>
class NTree
{
private:
    const T fKey;                   // T() for empty NTree
    NTree<T,N>* fNodes[N];          // N subtrees of degree N
    
    NTree();                        // sentinel constructor
    
public:
    static NTree<T,N> NIL;          // sentinel
    
    NTree( const T& aKey );         // a simple NTree with key and N subtrees
    
    NTree( const NTree& aOtherNTree );              // copy constructor
    virtual ~NTree();                               // destructor
    NTree& operator=( const NTree& aOtherNTree );   // assignment operator
    
    virtual NTree* clone();                         // clone a tree
    
    bool isEmpty() const;       // is tree empty
    const T& key() const;       // get key (node value)
    
    // indexer (allow for result modification by client - no const in result)
    NTree& operator[]( unsigned int aIndex ) const;
    
    // tree manipulators (using constant references)
    void attachNTree( unsigned int aIndex, const NTree<T,N>& aNTree );
    const NTree& detachNTree( unsigned int aIndex );
};

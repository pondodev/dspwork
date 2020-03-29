
// COS30008, Tutorial 10, 2019

#pragma once

#include "Queue.h"
#include "TreeVisitor.h"

#include <stdexcept>

template<class T, int N>
class NTree
{
private:
    T fKey;                         // T() for empty NTree
    NTree<T,N>* fNodes[N];          // N subtrees of degree N
    
    NTree() : fKey(T())             // sentinel constructor
    {
        for( int i = 0; i < N; i++ )
        {
            fNodes[i] = &NIL;
        }
    }
    
public:
    static NTree<T,N> NIL;          // sentinel
    
    NTree( const T& aKey ) : fKey(aKey)     // a simple NTree with key and N subtrees
    {
        for( int i = 0; i < N; i++ )
        {
            fNodes[i] = &NIL;
        }
    }

    NTree( const NTree& aOtherNTree )               // copy constructor
    {
        if ( aOtherNTree.isEmpty() )
        {
            throw std::domain_error( "Cannot copy an empty tree." );
        }
        
        fKey = aOtherNTree.fKey;

        for( int i = 0; i < N; i++ )
        {
            fNodes[i] = aOtherNTree.fNodes[i]->clone();
        }
    }
    
    virtual ~NTree()                                // destructor
    {
        for( int i = 0; i < N; i++ )
        {
            if ( !fNodes[i]->isEmpty() )
            {
                delete fNodes[i];
            }
        }
    }
    
    NTree& operator=( const NTree& aOtherNTree )    // assignment operator
    {
        if ( aOtherNTree.isEmpty() )
        {
            throw std::domain_error( "Cannot assign an empty tree." );
        }
        
        if ( this != &aOtherNTree )
        {
            // release this resources
            for( int i = 0; i < N; i++ )
            {
                if ( !fNodes[i]->isEmpty() )
                {
                    delete fNodes[i];
                }
            }
            
            // copy aOtherNTree
            fKey = aOtherNTree.fKey;
            
            for( int i = 0; i < N; i++ )
            {
                fNodes[i] = aOtherNTree.fNodes[i]->clone();
            }
        }
    }
    
    virtual NTree* clone()                          // clone a tree
    {
        if ( isEmpty() )
        {
            return this;
        }
        else
        {
            return new NTree( *this );
        }
    }
    
    bool isEmpty() const        // is tree empty
    {
        return this == &NIL;
    }

    const T& key() const        // get key (node value)
    {
        return fKey;
    }
    
    // indexer (allow for result modification by client - no const in result)
    NTree& operator[]( unsigned int aIndex ) const
    {
        if ( isEmpty() )
            throw std::domain_error( "Empty NTree!" );
        
        if ( aIndex < N )
        {
            return *fNodes[aIndex];        // return reference to subtree
        }
        else
            throw std::out_of_range( "Illegal subtree index!" );
    }
    
    // tree manipulators (using constant references)
    void attachNTree( unsigned int aIndex, const NTree<T,N>& aNTree )
    {
        if ( isEmpty() )
            throw std::domain_error( "Empty NTree!" );
        
        if ( aIndex < N )
        {
            if ( fNodes[aIndex] != &NIL )
                throw std::domain_error( "Non-empty subtree present!" );
            
            fNodes[aIndex] = (NTree<T,N>*)&aNTree;
        }
        else
            throw std::out_of_range( "Illegal subtree index!" );
    }

    const NTree& detachNTree( unsigned int aIndex )
    {
        if ( isEmpty() )
            throw std::domain_error( "Empty NTree!" );
        
        if ( (aIndex < N) && fNodes[aIndex] != &NIL )
        {
            const NTree<T,N>& Result = *fNodes[aIndex];     // obtain reference to subtree
            fNodes[aIndex] = &NIL;                          // set to NIL
            return Result;                                  // return subtree (reference)
        }
        else
            throw std::out_of_range( "Illegal subtree index!" );
    }
    
    // depth-first traversal
    void traverseDepthFirst( const TreeVisitor<T>& aVisitor ) const
    {
        if (!isEmpty())
        {
            aVisitor.preVisit(key());
            for (NTree<T, N>* n : fNodes)
            {
                n->traverseDepthFirst(aVisitor);
            }
            aVisitor.postVisit(key());
        }
    }
    
    // depth-first traversal
    void traverseBreadthFirst( const TreeVisitor<T>& aVisitor ) const
    {
        Queue<const NTree<T, N>*> q;

        if (!isEmpty()) q.enqueue(this);

        while (!q.isEmpty())
        {
            const NTree<T, N>& head = *q.top();
            q.dequeue();

            if (!head.isEmpty()) aVisitor.visit(head.key());
            for (NTree<T, N>* n : head.fNodes)
                if (!n->isEmpty())
                    q.enqueue(n);
        }
    }
};

template<class T, int N>
NTree<T,N> NTree<T,N>::NIL;

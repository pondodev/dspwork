
// COS30008, Problem Set 5, 2019

#pragma once

#include <string>

#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"

#include <stdexcept>

template<class T> 
class List
{
private:
	// auxiliary definition to simplify node usage
	typedef DoublyLinkedNode<T> Node;

	Node* fFirst;		    // the first element in the list
	Node* fLast;	        // the last element in the list
	unsigned int fCount;	// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
    typedef DoublyLinkedNodeIterator<T> Iterator;

#ifdef A
    
    List()                          // default constructor - creates empty list
    {
        fCount = 0;
        fFirst = &Node::NIL;
        fLast = &Node::NIL;
    }
    
#endif
    
    ~List()                         // destructor - frees all nodes
    {
        while ( fFirst != &Node::NIL )
        {
            Node* temp = (Node *)&fFirst->getNext();    // get next node (to become top)
            fFirst->remove();                           // move first node
            delete fFirst;                              // free node memory
            fFirst = temp;                              // make temp the new top
        }
    }
    
    bool isEmpty() const    // Is list empty?
    {
        return fFirst == &Node::NIL;  // or: return fCount == 0;
    }
    
    int size() const        // list size
    {
        return fCount;
    }
    
    void push_front( const T& aElement )  // adds a node initialized with aElement at front
    {
        Node* lNewElement = new Node( aElement );   // create a new node
        
        if ( fFirst == &Node::NIL )                 // Is this the first node?
        {
            fFirst = lNewElement;                   // make lNewNode first node
            fLast = lNewElement;                    // make lNewNode last node as well
        }
        else
        {
            fFirst->push_front( *lNewElement );     // make lNewElement previous of top
            fFirst = lNewElement;                   // make lNewNode first node
        }
        
        fCount++;                                   // increment count
    }
    
#ifdef B
    
    void push_back( const T& aElement ) // adds a node initialized with aElement at back
    {
        Node* lNewElement = new Node( aElement );   // create a new node

        if ( fFirst == &Node::NIL )                 // Is this the first node?
        {
            fFirst = lNewElement;                   // make lNewNode first node
            fLast = lNewElement;                    // make lNewNode last node as well
        }
        else
        {
            fLast->push_back( *lNewElement );     // make lNewElement previous of top
            fLast = lNewElement;                   // make lNewNode first node
        }
        
        fCount++;                                   // increment count
    }
    
#endif
    
#ifdef C
    
    void remove( const T& aElement )        // remove node that matches aElement from list
    {
        Node* n = fFirst;

        while (n != &Node::NIL)
        {
            if (n->getValue() == aElement)
            {
                if (n == fFirst)
                {
                    fFirst = (Node*)&n->getNext();
                }

                if (n == fLast)
                {
                    fLast = (Node*)&n->getPrevious();
                }

                fCount--;
                n->remove();
                delete n;
            }

            n = (Node*)&n->getNext();
        }
    }
    
#endif
    
#ifdef D
    
    const T& operator[]( unsigned int aIndex ) const    // list indexer
    {
        if (aIndex >= fCount) throw std::range_error("index out of bounds");
        Node* n = fFirst;

        for (int i = 0; i < aIndex; i++)
            n = (Node*)&n->getNext();

        return n->getValue();
    }
    
#endif
    
#ifdef A
    
    Iterator begin() const          // return a forward iterator
    {
        return Iterator(*fFirst).begin();
    }
    
    Iterator end() const            // return a forward end iterator
    {
        // define
        return Iterator(*fLast).end();
    }
    
    Iterator rbegin() const         // return a backwards iterator
    {
        return Iterator(*fFirst).rbegin();
    }
    
    Iterator rend() const            // return a backwards end iterator
    {
        // define
        return Iterator(*fLast).rend();
    }
    
#endif

};

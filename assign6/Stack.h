#pragma once 

#include "List.h"
#include <stdexcept>

template<class T>
class Stack
{
    private:
        List<T> fElements;

    public:
        bool isEmpty() const
        {
            return fElements.isEmpty();
        }

        int size() const
        {
            return fElements.size();
        }

        void push(const T& aItem)
        {
            fElements.push_front(aItem);
        }

        void pop()
        {
            if (isEmpty()) throw "no elements left in stack";
            fElements.remove(fElements[0]);
        }

        const T& top() const
        {
            return fElements[0];
        }
};

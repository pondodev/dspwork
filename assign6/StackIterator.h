#pragma once

#include "Stack.h"

template<class T>
class StackIterator
{
    private:
        Stack<T> fStack;

    public:
        StackIterator(const Stack<T>& aStack)
        {
            fStack = aStack;
        }

        const T& operator*() const
        {
            return fStack.top();
        }

        StackIterator&operator++()
        {
            fStack.pop();
            return *this;
        }

        StackIterator operator++(int)
        {
            StackIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const StackIterator& aOtherIter) const
        {
            return aOtherIter.fStack.size() == fStack.size();
        }

        bool operator!=(const StackIterator& aOtherIter) const
        {
            return !(*this == aOtherIter);
        }

        StackIterator begin() const
        {
            return *this;
        }

        StackIterator end() const
        {
            return StackIterator(Stack<T>());
        }
};

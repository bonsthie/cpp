#pragma once

#include <stack>
#include "log.h"

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {
        LOG("constructor MutantStack<T> empty");
    }

    MutantStack(const MutantStack &src) : std::stack<T>(src) {
        LOG("constructor MutantStack copy");
    }

    ~MutantStack() {
        LOG("destructor MutantStack");
    }

    MutantStack &operator=(const MutantStack &src) {
        if (this != &src) {
            std::stack<T>::operator=(src);
        }
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }

    const_iterator begin() const { return std::stack<T>::c.begin(); }
    const_iterator end() const { return std::stack<T>::c.end(); }
};

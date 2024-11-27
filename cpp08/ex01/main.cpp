#include "Span.h"
#include <iostream>
#include <stdexcept>

int main() {
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    try {
        Span sp = Span(2);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);

    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
}

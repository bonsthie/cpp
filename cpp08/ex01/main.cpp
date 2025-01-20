#include <iostream>
#include <vector>
#include "Span.h"

int main() {
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    try {
        Span sp = Span(2);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(2);
        numbers.push_back(3);
        numbers.push_back(4);
        numbers.push_back(5);

        Span sp = Span(10);

        sp.addNumber(numbers.begin(), numbers.end());
        sp.addNumber(numbers.begin(), numbers.begin() + 3);
        std::cout << "Successfully added numbers using iterators." << std::endl;

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int> numbers;
        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);
        numbers.push_back(40);
        numbers.push_back(50);
        numbers.push_back(60);

        Span sp = Span(5);

        sp.addNumber(numbers.begin(), numbers.end());
    } catch (std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

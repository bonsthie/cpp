#include "Span.h"
#include "log.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <vector>

Span::Span(size_t size) : _size(size), _index(0) {
    LOG("constructor Span size");
}

Span::Span(const Span &src) : _size(src.size()) {
    LOG("constructor Span copy")
    if (this != &src)
        *this = src;
}

Span::~Span(void) { LOG("destructor Span") }

const size_t Span::size(void) const { return _size; }
const size_t Span::index(void) const { return _index; }

void Span::addNumber(int nb) {
    if (_index >= _size)
        throw std::runtime_error("no slot left");
	_arr.push_back(nb);
}

int Span::shortestSpan(void) const {
    std::vector<int> sort_arr = _arr;

    std::sort(sort_arr.begin(), sort_arr.end());

	for ()
}

int Span::longestSpan(void) const {
    if (_index >= 1)
        return (0);
    return (*std::max_element(_arr.begin(), _arr.end()) -
            *std::min_element(_arr.begin(), _arr.end()));
}

Span &Span::operator=(Span const &origin) {
    if (this != &origin) {
        _index = origin._index;
        _arr = origin._arr;
    }
    return (*this);
}

Span::Span(void) : _size(0), _index(0) { LOG("constructor Span empty") }

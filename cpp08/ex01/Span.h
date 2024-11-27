#pragma once

#include <cstddef>
#include <vector>

class Span {
  public:
    Span(const Span &ref);
    Span(size_t size);
    ~Span(void);

    Span &operator=(Span const &src);

    size_t size(void) const;
    size_t index(void) const;
    int   *c_arr(void) const;

    void addNumber(int nb);

    int shortestSpan(void) const;
    int longestSpan(void) const;

  private:
    Span(void);

    std::vector<int> _arr;
    const size_t     _size;
    size_t           _index;
};

#pragma once

#include "log.h"
#include <ostream>
#include <cstring>

template <typename T> class Array {
public:
  Array(const Array<T> &origin);
  Array(unsigned int size);
  Array(void);
  virtual ~Array(void);

  T *getArray(void) const;
  unsigned int getSize(void) const;

  Array<T> &operator=(const Array<T> &origin);
  T &operator[](unsigned int offset);

private:
  unsigned int _size;
  T *_arr;
};

template <typename T> Array<T>::Array(const Array<T> &origin) {
  *this = origin;
  LOG("by reference constructor");
}

template <typename T> Array<T>::Array(void) : _size(1), _arr(new T[1]) {
  LOG("default constructor");
}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size), _arr(new T[size]) {
  LOG("size constructor");
}

template <typename T> Array<T>::~Array(void) {
  LOG("destructor");
  if (_arr)
    delete[] _arr;
}

template <typename T> T *Array<T>::getArray(void) const { return _arr; }
template <typename T> unsigned int Array<T>::getSize(void) const { return _size; }

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &origin) {
  if (this != &origin) {
    _size = origin.getSize();
    _arr = new T[_size];
    if (_arr)
      memcpy(_arr, origin.getArray(), _size * sizeof(T));
  }
  return (*this);
}

template <typename T> T &Array<T>::operator[](unsigned int offset) {
	return _arr[offset];
}

template <typename T>
std::ostream &operator<<(std::ostream &oStream, const Array<T> &value) {

  T *arr = value.getArray();
  unsigned len = value.getSize();
  for (unsigned i = 0; i < len; i++)
    oStream << arr[i];
  return (oStream);
}

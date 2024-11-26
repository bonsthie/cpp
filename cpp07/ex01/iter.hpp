#pragma once

#include <cstddef>

template <typename T> void iter(T *arr, size_t size, void func(T&)) {
  for (size_t i = 0; i < size; i++)
    func(arr[i]);
}

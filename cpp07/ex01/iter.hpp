#pragma once

#include <cstddef>

template <typename T, typename F> void iter(T *arr, size_t size, void func(F&)) {
  for (size_t i = 0; i < size; i++)
    func(arr[i]);
}

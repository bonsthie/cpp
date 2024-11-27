#pragma once
#include <algorithm>

template <typename T> int *easyfind(T arr, const int toFind) {
  typename T::iterator it = std::find(arr.begin(), arr.end(), toFind);
  if (it == arr.end())
    return (0);
  return &(*it);
}

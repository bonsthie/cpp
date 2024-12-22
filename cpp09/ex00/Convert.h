#pragma once

#include <sstream>

template <typename T> T strToType(const std::string &str) {
  std::stringstream ss(str);
  T result;
  ss >> result;
  return result;
}

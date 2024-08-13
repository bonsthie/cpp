/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:05:46 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 14:42:18 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.h"
#include <cstddef>

#if defined(__AVX2__)

#include <immintrin.h>

size_t __avx2_find(const std::string &file, const std::string &s1, size_t pos) {
  const char *str = file.c_str();
  const char *pattern = s1.c_str();
  size_t file_len = file.length();
  size_t pat_len = s1.length();

  if (pat_len == 0)
    return pos;
  if (file_len < pat_len)
    return std::string::npos;

  __m256i setFirstChar = _mm256_set1_epi8(pattern[0]);
  __m256i data;
  int maskFirstChar;

  while (pos <= file_len - 32 - pat_len) {
    data = _mm256_loadu_si256((const __m256i *)(str + pos));
    maskFirstChar = _mm256_movemask_epi8(_mm256_cmpeq_epi8(data, setFirstChar));

    if (maskFirstChar) {
      size_t candidate_pos = pos + __builtin_ctz(maskFirstChar);
      if (candidate_pos + pat_len <= file_len &&
          file.compare(candidate_pos, pat_len, s1) == 0) {
        return candidate_pos;
      }
      pos = candidate_pos + 1;
    } else
      pos += 32;
  }
  for (; pos < file_len; ++pos) {
    if (file.compare(pos, pat_len, s1) == 0) {
      return pos;
    }
  }

  return std::string::npos;
}

#define FIND(file, s1, pos) __avx2_find(file, s1, pos)
#else
#define FIND(file, s1, pos) file.find(s1, pos)
#endif

int File::sed(const std::string &s1, const std::string &s2) {
  if (s1.empty() || s2.empty()) {
    std::cerr << "sed :invalid parameter" << std::endl;
    return (1);
  }
  size_t pos = 0;

  pos = FIND(_strfile, s1, pos);
  while (pos < _strfile.length()) {
    _strfile.erase(pos, s1.length());
    _strfile.insert(pos, s2);
    pos = FIND(_strfile, s1, pos + s2.length());
  }
  return (0);
}

int sed(const std::string &file, const std::string &s1, const std::string &s2) {
  File input(file);
  if (!input.is_open())
    return (1);
  return (input.sed(s1, s2));
}

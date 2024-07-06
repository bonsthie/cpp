/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:13:27 by babonnet          #+#    #+#             */
/*   Updated: 2024/07/06 15:19:49 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

#if defined(__AVX512BW__)
#	define SIMD_LVL 512
#elif defined(__AVX2__)
#	define SIMD_LVL 256
#elif defined(__SSE4_2__)
#	define SIMD_LVL 128
#else
#	define SIMD_LVL 0
#endif

#if SIMD_LVL >= 512
#	define TAG(x) _mm512_##x
#	define TAG_SI(x) _mm512_##x##_si512
#	define TYPE __m512i
#	define SIZE 64
#	include "megaphone.h"
#endif
 
#if SIMD_LVL >= 256
#	define TAG(x) _mm256_##x
#	define TAG_SI(x) _mm256_##x##_si256
#	define TYPE __m256i
#	define SIZE 32
#	include "megaphone.h"
#endif
 
#if SIMD_LVL >= 128
#	define TAG(x) _mm_##x
#	define TAG_SI(x) _mm_##x##_si128
#	define TYPE __m128i
#	define SIZE 16
#	include "megaphone.h"
#endif

void to_uppercase(char *str) {
  size_t len = strlen(str);
  size_t i = 0;

#if SIMD_LVL >= 512
  _mm512_toupper_epi8(str, &i, len);
#endif
#if SIMD_LVL >= 256
  _mm256_toupper_epi8(str, &i, len);
#endif
#if SIMD_LVL >= 128
  _mm_toupper_epi8(str, &i, len);
#endif
  for (; i < len; i++) {
    str[i] = std::toupper(str[i]);
  }
}

void megaphone(char **av) {
  if (!*av) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (; *av; av++) {
      to_uppercase(*av);
      std::cout << *av << " ";
    }
  }
  std::cout << std::endl;
}

int main(int, char **av) {
#if defined(__AVX515BW__)
  std::cout << "fseffsfsf" << std::endl;
#endif
  megaphone(++av);
  return 0;
}

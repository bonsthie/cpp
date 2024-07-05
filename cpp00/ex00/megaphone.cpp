/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:13:27 by babonnet          #+#    #+#             */
/*   Updated: 2024/07/06 01:26:56 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

#if defined(__AVX2__)
#	define TAG(x) _mm_##x
#	define TAG_SI(x) _mm_##x##_si128
#	define TYPE __m128i
#	define SIZE 16
#	include "megaphone.h"

#	define TAG(x) _mm256_##x
#	define TAG_SI(x) _mm256_##x##_si256
#	define TYPE __m256i
#	define SIZE 32
#	include "megaphone.h"
#endif

void to_uppercase(char *str) {
  size_t len = strlen(str);
  size_t i = 0;

#if defined(__AVX2__)
  _mm256_toupper_epi8(str, &i, len);
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
  megaphone(++av);
  return 0;
}

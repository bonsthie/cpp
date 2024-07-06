/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:13:27 by babonnet          #+#    #+#             */
/*   Updated: 2024/07/06 15:20:34 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

#include "simd.h"

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

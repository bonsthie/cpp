/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:13:27 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 16:49:11 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

#include "simd.h"

void to_uppercase(std::string &str) {
  size_t len = str.length();
  char *cstr = const_cast<char *>(str.c_str());
  size_t i = 0;

#if SIMD_LVL >= 512
  _mm512_toupper_epi8(cstr, &i, len);
#endif
#if SIMD_LVL >= 256
  _mm256_toupper_epi8(cstr, &i, len);
#endif
#if SIMD_LVL >= 128
  _mm_toupper_epi8(cstr, &i, len);
#endif
  for (; i < len; i++) {
    cstr[i] = std::toupper(cstr[i]);
  }
}

void megaphone(char **av) {
  std::string str;
  if (!*av) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (; *av; av++) {
      str.append(*av);
    }
  }
  to_uppercase(str);
  std::cout << str << std::endl;
}

int main(int, char **av) {
  megaphone(++av);
  return 0;
}

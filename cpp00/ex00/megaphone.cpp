/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:13:27 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/30 16:40:11 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

#if defined(__AVX2__)

#include <immintrin.h>
#include <cstring>

__m256i _mm256_islower_epi8(__m256i data) {
    return _mm256_and_si256(_mm256_cmpgt_epi8(data, _mm256_set1_epi8('a' - 1)),
                            _mm256_cmpgt_epi8(_mm256_set1_epi8('z'), data));
}

__m256i _mm256_toupper_epi8(__m256i data) {
    __m256i mask = _mm256_islower_epi8(data);
    __m256i upper_mask = _mm256_set1_epi8(0xDF);
    __m256i lower_to_upper = _mm256_and_si256(data, upper_mask);

    return _mm256_or_si256(_mm256_and_si256(mask, lower_to_upper), _mm256_andnot_si256(mask, data));
}

void to_uppercase(char *str) {
    size_t len = strlen(str);
    size_t i = 0;

    for (; i + 32 <= len; i += 32) {
        __m256i data = _mm256_loadu_si256((__m256i *)(str + i));
        data = _mm256_toupper_epi8(data);
        _mm256_storeu_si256((__m256i *)(str + i), data);
    }
    for (; str[i]; i++) {
		str[i] = toupper(str[i]);
    }
}
#else

void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
		str[i] = toupper(str[i]);
    }
}

#endif

void megaphone(char **av) {
    if (!*av)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (; *av; av++) {
        to_uppercase(*av);
        std::cout << *av;
    }
    std::cout << std::endl;
}

int main(int __attribute__((unused)) ac, char **av) { megaphone(++av); }

#include <immintrin.h>
#include <iostream>

__m256i __m256i_toupper_epi8(__m256i str) {
    __m256i a_val = _mm256_set1_epi8('a');
    __m256i z_val = _mm256_set1_epi8('z');
    __m256i offset = _mm256_set1_epi8(32);

    // Generate masks based on unsigned range comparison assuming no negative values in ASCII range
    __m256i mask = _mm256_and_si256(
        _mm256_cmpgt_epi8(str, _mm256_sub_epi8(a_val, _mm256_set1_epi8(1))), // str > 'a' - 1
        _mm256_cmpgt_epi8(_mm256_add_epi8(z_val, _mm256_set1_epi8(1)), str)  // 'z' + 1 > str
    );

    // Apply mask to convert only lowercase letters
    return _mm256_sub_epi8(str, _mm256_and_si256(mask, offset));
}

int main(int ac, char **av) {
    __m256i vec = _mm256_loadu_si256((__m256i*)av[1]);
    __m256i upper_vec = __m256i_toupper_epi8(vec);
    _mm256_storeu_si256((__m256i*)av[1], upper_vec);

    std::cout << "Converted to uppercase: " << av[1] << std::endl;
    return 0;
}

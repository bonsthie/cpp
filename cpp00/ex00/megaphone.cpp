#include <iostream>
#include <algorithm>
#include <cctype>

#if defined(__AVX2__)
#include <immintrin.h>

__m256i _mm256_islower_epi8(__m256i data)
{
    return _mm256_and_si256(
	 _mm256_cmpgt_epi8(data, _mm256_set1_epi8('a' - 1)),
     _mm256_cmpgt_epi8(_mm256_set1_epi8('z'), data));
}

__m256i _mm256_toupper_epi8(__m256i data)
{
    __m256i mask = _mm256_islower_epi8(data);
    __m256i upper_mask = _mm256_set1_epi8(0xDF);
    __m256i lower_to_upper = _mm256_and_si256(data, upper_mask);

    return _mm256_or_si256(
		_mm256_and_si256(mask, lower_to_upper),
		_mm256_andnot_si256(mask, data));
}

void to_upper_avx2(std::string& str)
{
    size_t len = str.size();
    size_t i = 0;

    for (; i + 32 <= len; i += 32) {
        __m256i data = _mm256_loadu_si256((__m256i*)(str.data() + i));
        data = _mm256_toupper_epi8(data);
        _mm256_storeu_si256((__m256i*)(str.data() + i), data);
    }
	std::transform(str.begin() + i, str.end(), str.begin() + i, (int(*)(int)) std::toupper);
}
#endif

void megaphone(char **av)
{
	av++;
	if (!*av)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (; *av; av++)
	{
		std::string str = *av;
#if defined(__AVX2__)
		to_upper_avx2(str);
#else
		std::transform(str.begin(), str.end(), str.begin(),  (int(*)(int)) std::toupper);
#endif
		std::cout << str;
	}
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	megaphone(av);
}

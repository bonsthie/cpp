#include <cstring>
#include <iostream>
#include <algorithm>
#include <cctype>

#if defined(__AVX2__)
	#include <immintrin.h>

	void to_upper_avx2(char *str, int len)
	{
		int i = 0;
		__m256i a_to_z_mask = _mm256_set1_epi8(0xDF);

		for (; i <= len - 32; i += 32) {
			__m256i data = _mm256_loadu_si256((__m256i*)(str + i));
			data = _mm256_and_si256(data, a_to_z_mask);
			_mm256_storeu_si256((__m256i*)(str + i), data);
		}
		for (; i < len; ++i) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				str[i] -= 'a' - 'A';
			}
		}
	}
#endif

int megaphone(char **av)
{
	av++;
	if (!*av)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (; *av; av++)
	{
		std::string str = *av;
#if defined(__AVX2__)
		to_upper_avx2(&str[0], str.length());
#else
		std::transform(str.begin(), str.end(), str.begin(),  (int(*)(int)) std::toupper);
#endif
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}

int main(int ac, char **av)
{
	megaphone(av);
}

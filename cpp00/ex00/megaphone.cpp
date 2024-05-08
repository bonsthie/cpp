#include <iostream>
#include <algorithm>
#include <cctype>

#if defined(__AVX2__)
#include <immintrin.h>

__m256i _mm256_isalpha_epi8(__m256i data)
{
	__m256i mask;
	__m256i mask_a = _mm256_set1_epi8('a');
	__m256i mask_z = _mm256_set1_epi8('z');

	mask = _mm256_cmpgt_epi8(data, mask_a);
	mask ^= _mm256_cmpgt_epi8(data, mask_z);
	return (mask);
}

__m256i _mm256_toupper_epi8(__m256i data)
{
	__m256i result;
	__m256i mask = _mm256_isalpha_epi8(data);
	__m256i upper_mask = _mm256_set1_epi8(0xDF);

	result = _mm256_or_si256(_mm256_and_si256(mask, _mm256_and_si256(data, upper_mask)),\
			_mm256_andnot_si256(mask, data));
	return (result);
}

void to_upper_avx2(std::string str)
{
	int len = str.size();
	int i = 0;

	for (; i <= len - 32; i += 32)
	{
		__m256i data = _mm256_loadu_si256((__m256i*)(str.data() + i));
		data = _mm256_toupper_epi8(data);
		_mm256_storeu_si256((__m256i*)(str.data() + i), data);
	}
	for (; i < len; ++i)
		str[i] = toupper(str[i]);
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
		to_upper_avx2(str);
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

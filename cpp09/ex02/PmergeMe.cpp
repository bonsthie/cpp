#include <algorithm>
#include <cstring>
#include <iostream>
#include <log.h>
#include <stdexcept>
#include <stdint.h>
#include <stdlib.h>
#include <utility>
#include <vector>

typedef std::vector<std::pair<uint32_t, uint32_t> > pair_vector_u32_t;

/*
 * Parses the next number from the string.
 * Returns -1 if no number is found.
 * Throws std::runtime_error for invalid input.
 */
static int64_t getNextNumber(char **str) {
    while (isspace(**str))
        (*str)++;

    if (**str == 0)
        return -1;
    int64_t nb = strtol(*str, str, 0);
    if (*str == NULL || nb < 0 || (**str != 0 && **str != ' '))
        throw std::runtime_error("Invalid input");
    return nb;
}

/*
 * Reads a string of numbers and creates pairs.
 * pair.first will always be the biggest
 * Sets odd_pair to true if the input ends with an incomplete pair.
 * Throws std::runtime_error for invalid input.
 */
static void init_merge_pair(const char *input_str, pair_vector_u32_t &res_vector, bool &odd_pair) {
    // cast in char only for the strtol func this will not change the string
    char *str = const_cast<char *>(input_str);

    odd_pair = false;

    while (*str) {
        int64_t n1 = getNextNumber(&str);
        int64_t n2 = getNextNumber(&str);
        if (n2 == -1)
            odd_pair = true;

        if (n2 > n1) {
            std::swap(n1, n2);
        }
        res_vector.push_back(std::make_pair(static_cast<uint32_t>(n1), static_cast<uint32_t>(n2)));
    }
}

bool compareByFirst(const std::pair<uint32_t, uint32_t> &a,
                    const std::pair<uint32_t, uint32_t> &b) {
    return a.first < b.first;
}

void merge(pair_vector_u32_t &vec, size_t left, size_t mid, size_t right) {
    pair_vector_u32_t temp;
    size_t            i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (compareByFirst(vec[i], vec[j])) {
            temp.push_back(vec[i++]);
        } else {
            temp.push_back(vec[j++]);
        }
    }
    while (i <= mid)
        temp.push_back(vec[i++]);
    while (j <= right)
        temp.push_back(vec[j++]);

    for (size_t k = 0; k < temp.size(); ++k) {
        vec[left + k] = temp[k];
    }
}

void merge_sort_pair(pair_vector_u32_t &vec, size_t left, size_t right) {
    if (left >= right)
        return;

    size_t mid = left + (right - left) / 2;

    merge_sort_pair(vec, left, mid);
    merge_sort_pair(vec, mid + 1, right);

    merge(vec, left, mid, right);
}

void insertion(std::vector<uint32_t>& arr, uint32_t value) 
{
    int left = 0;
    int right = arr.size() - 1;
    int pos = arr.size();
    
    while (left <= right) 
    {
        int mid = left + ((right - left) >> 1);
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            pos = mid;
            right = mid - 1;
        }
    }

	arr.push_back(0); 
    std::memmove(&arr[pos + 1], &arr[pos], (arr.size() - pos - 1) * sizeof(int));
    arr[pos] = value;
}

std::vector<uint32_t> pmergeme(const char *str) {
    pair_vector_u32_t pair_vector;
    bool              odd = false;

    init_merge_pair(str, pair_vector, odd);

	size_t size = pair_vector.size() - (odd == true);

#ifdef VERBOSE
    for (pair_vector_u32_t::iterator it = pair_vector.begin(); it != pair_vector.end(); it++) {
        LOG("pair [ " << it->first << ", " << it->second << " ]")
    }
#endif
    merge_sort_pair(pair_vector, 0, size - 1);

#ifdef VERBOSE
    for (pair_vector_u32_t::iterator it = pair_vector.begin(); it != pair_vector.end(); it++) {
        LOG("pair after first sort [ " << it->first << ", " << it->second << " ]")
    }
#endif
    std::vector<uint32_t> res(size);

	for (size_t i = 0; i < size; i++) {
		res[i] = pair_vector[i].first;
	}

	for (size_t i = 0; i < size; i++) {
		insertion(res, pair_vector[i].second);
	}

	if (odd == true) {
		insertion(res, pair_vector[size].first);
	}

    return (res);
}

#include <PmergeMe.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <utility>
#include <vector>

/*
 * Reads a string of numbers and creates pairs.
 * pair.first will always be the biggest
 * Sets odd_pair to true if the input ends with an incomplete pair.
 */
static void init_merge_pair(const std::vector<uint32_t> &input, pair_vector_u32_t &res_vector,
                            bool &odd_pair) {
    odd_pair = false;

    for (size_t i = 0; i < input.size() - 1; i += 2) {
        int64_t n1 = input[i];
        int64_t n2 = input[i + 1];

        if (n2 > n1) {
            std::swap(n1, n2);
        }
        res_vector.push_back(std::make_pair(static_cast<uint32_t>(n1), static_cast<uint32_t>(n2)));
    }
    if (input.size() % 2) {
        odd_pair = true;
        res_vector.push_back(
            std::make_pair(static_cast<uint32_t>(-1), static_cast<uint32_t>(input.back())));
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

void insertion(std::vector<uint32_t> &arr, uint32_t value) {
    int left = 0;
    int right = arr.size() - 1;
    int pos = arr.size();

    while (left <= right) {
        int mid = left + ((right - left) / 2);
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


void pmergeme(char **str) {
    pair_vector_u32_t pair_vector;
    bool              odd = false;

    std::vector<uint32_t> start = create_list(str);

    init_merge_pair(start, pair_vector, odd);

    size_t size = pair_vector.size() - (odd == true);

    TIME(merge_time, merge_sort_pair(pair_vector, 0, size - 1);)

    std::vector<uint32_t> res(size);

	TIME(insert_time,
    for (size_t i = 0; i < size; i++) {
        res[i] = pair_vector[i].first;
    }

    for (size_t i = 0; i < size; i++) {
        insertion(res, pair_vector[i].second);
    }

    if (odd == true) {
        insertion(res, pair_vector[size].first);
    })

	print_res(start, res, merge_time, insert_time);

}

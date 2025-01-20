#pragma once

#include <stdint.h>
#include <sys/time.h>
#include <vector>

typedef std::vector<std::pair<uint32_t, uint32_t> > pair_vector_u32_t;

#define TIME(time_value, routine)                                                                  \
    double time_value = 0;                                                                         \
    {                                                                                              \
        struct timeval start, end;                                                                \
        gettimeofday(&start, NULL);                                                               \
        routine                                                                                   \
        gettimeofday(&end, NULL);                                                                 \
        time_value = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);            \
    }

std::vector<uint32_t> create_list(char **str);

void print_res(const std::vector<uint32_t> &start,
				const std::vector<uint32_t> &res,
				double merge_time,
				double insert_time);

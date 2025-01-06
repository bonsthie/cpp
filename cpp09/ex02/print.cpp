#include <stdint.h>
#include <iostream>
#include <vector>


static void print_vec(const std::vector<uint32_t> &vec) {
    size_t size = vec.size();

    for (size_t i = 0; i < size; i++) {
        std::cout << vec[i];
        if (i < size - 1)
            std::cout << " ";
    }
}

void print_res(const std::vector<uint32_t> &start,
				const std::vector<uint32_t> &res,
				double merge_time,
				double insert_time) {

    std::cout << "before :";
    print_vec(start);
    std::cout << std::endl;

    std::cout << "after : ";
    print_vec(res);
    std::cout << "\n";

    std::cout << "Time to process a range of " << res.size()
              << " elements with std::pair : " << merge_time << " us\n";
    std::cout << "Time to process a range of " << res.size()
              << " elements with std::vector : " << insert_time << " us\n";
}

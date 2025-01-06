#include <cctype>
#include <cstdlib>
#include <stdexcept>
#include <stdint.h>
#include <vector>

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
    if (*str == NULL || nb < 0 || **str != 0)
        throw std::runtime_error("Invalid input");
    return nb;
}

std::vector<uint32_t> create_list(char **str) {

    std::vector<uint32_t> res;

    while (*str) {
        res.push_back(getNextNumber((char **)str));
        str++;
    }
    return res;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:59:51 by bonsthie          #+#    #+#             */
/*   Updated: 2025/01/30 11:26:47 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.h"
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <stdint.h>
#include <sys/ioctl.h>
#include <unistd.h>

static int rpn_mult(int nb1, int nb2) { return nb1 * nb2; }
static int rpn_sub(int nb1, int nb2) { return nb1 - nb2; }
static int rpn_add(int nb1, int nb2) { return nb1 + nb2; }

static int rpn_div(int nb1, int nb2) {
    if (nb2 == 0)
        throw std::runtime_error("you can't do a division by 0");
    return nb1 / nb2;
}

static int rpn_mod(int nb1, int nb2) {
    if (nb2 == 0)
        throw std::runtime_error("you can't do a modulo by 0");
    return nb1 % nb2;
}

static void rpn_sign(const char *str, std::stack<int> &stack, int sign(int, int)) {
    int a, b;

    if (stack.size() < 2)
        throw std::runtime_error("you can't do a action on less than 2 number");
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
    stack.push(sign(a, b));
    str++;
    if (*str != ' ' && *str != 0)
        throw std::runtime_error("invalid formating");
}

static int get_term_width() {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return w.ws_col;
    } else {
        return 80; // Default fallback width
    }
}

// create a linter error message with the max with of the terminal
static std::string rpn_error(const char *msg, const char *start, size_t error_index) {
    size_t term_size = get_term_width();

    std::string str(start);

	size_t trim_index = (error_index + term_size - 1) & ~(term_size - 1);
    if (trim_index > str.size())
        trim_index = str.size();
    std::string tri_str_start = str.substr(0, trim_index);
    std::string space_index(error_index, ' ');

    std::ostringstream o;
    o << msg << "\n\n" << tri_str_start << "\n" << space_index << "^";

    return o.str();
}

// dummy switch case and if else because i can't use unordored map.............
static void _action(const char *index, std::stack<int> &stack) {
    if (isdigit(*index))
        stack.push(*index - '0');

    else if (*index == '*')
        rpn_sign(index, stack, rpn_mult);
    else if (*index == '/')
        rpn_sign(index, stack, rpn_div);
    else if (*index == '+')
        rpn_sign(index, stack, rpn_add);
    else if (*index == '-')
        rpn_sign(index, stack, rpn_sub);
    else if (*index == '%')
        rpn_sign(index, stack, rpn_mod);
    else if (*index == ' ')
        return; // ' ' do nothing
    else
        throw std::runtime_error("invalid formating");
}

void rpn(const char *str) {
    const char     *index = str;
    std::stack<int> stack;

    while (*index) {
        try {
            _action(index, stack);
        } catch (std::exception &e) {
            throw std::runtime_error(rpn_error(e.what(), str, index - str));
        }
        index++;
    }
    if (stack.size() != 1)
        throw std::runtime_error("invalid formating");
    std::cout << stack.top() << std::endl;
}

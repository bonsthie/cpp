/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:59:51 by bonsthie          #+#    #+#             */
/*   Updated: 2024/12/25 16:34:33 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.h"
#include <ctype.h>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <stdint.h>

int rpn_mult(int nb1, int nb2) { return nb1 * nb2; }
int rpn_sub(int nb1, int nb2) { return nb1 - nb2; }
int rpn_add(int nb1, int nb2) { return nb1 + nb2; }

int rpn_div(int nb1, int nb2) {
    if (nb2 == 0)
        throw std::runtime_error("you can't do a division by 0");
    return nb1 / nb2;
}

int rpn_mod(int nb1, int nb2) {
    if (nb2 == 0)
        throw std::runtime_error("you can't do a modulo by 0");
    return nb1 % nb2;
}

static const operatorMap operator_map = {
    {'*', rpn_mult},
	{'/', rpn_div},
	{'+', rpn_add},
	{'-', rpn_sub},
	{'%', rpn_mod},
};

void rpn_sign(const char *str, std::stack<int> &stack, int sign(int, int)) {
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

void rpn(const char *str) {
    std::stack<int> stack;

    while (*str) {
        if (isdigit(*str))
            stack.push(*str - '0');
        else if (*str != ' ') {
            operatorMap::const_iterator it = operator_map.find(*str);
            if (it == operator_map.end())
                throw std::runtime_error("invalid formating");
            rpn_sign(str, stack, it->second);
        }
        str++;
    }
    if (stack.size() != 1)
        throw std::runtime_error("invalid formating");
    std::cout << stack.top() << std::endl;
}
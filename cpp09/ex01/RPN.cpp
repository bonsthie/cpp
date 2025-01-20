/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:59:51 by bonsthie          #+#    #+#             */
/*   Updated: 2024/12/30 11:26:32 by babonnet         ###   ########.fr       */
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

// dummy switch case and if else because i can't use unordored map.............
rpn_type get_rpn_type(const char c) {
    if (isdigit(c))
        return RPN_NUM;
    else if (c == '*')
        return RPN_MULT;
    else if (c == '/')
        return RPN_DIV;
    else if (c == '+')
        return RPN_ADD;
    else if (c == '-')
        return RPN_SUB;
    else if (c == '%')
        return RPN_MOD;
    else if (c == ' ')
        return RPN_SPACE;
    return RPN_ERR;
}

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
        switch (get_rpn_type(*str)) {
        case RPN_NUM:
            stack.push(*str - '0');
            break;
        case RPN_MULT:
            rpn_sign(str, stack, rpn_mult);
            break;
        case RPN_DIV:
            rpn_sign(str, stack, rpn_div);
            break;
        case RPN_SUB:
            rpn_sign(str, stack, rpn_sub);
            break;
        case RPN_ADD:
            rpn_sign(str, stack, rpn_add);
            break;
        case RPN_MOD:
            rpn_sign(str, stack, rpn_mod);
            break;
        case RPN_SPACE:
            break;
        default:
			throw std::runtime_error("invalid formating");
        }
        str++;
    }
    if (stack.size() != 1)
		throw std::runtime_error("invalid formating");
    std::cout << stack.top() << std::endl;
}

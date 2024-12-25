#include "RPN.h"
#include <ctype.h>
#include <iostream>
#include <stack>
#include <stdint.h>

int rpn_mult(int nb1, int nb2) { return nb1 * nb2; }
int rpn_div(int nb1, int nb2) { return nb1 / nb2; }
int rpn_sub(int nb1, int nb2) { return nb1 - nb2; }
int rpn_add(int nb1, int nb2) { return nb1 + nb2; }
int rpn_mod(int nb1, int nb2) { return nb1 % nb2; }

// dummy switch case and if else because i can't use map.......................
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

int rpn_sign(const char *str, std::stack<int> &stack, int sign(int, int)) {
    int a, b;

    if (stack.size() < 2)
        return 1;
    b = stack.top();
    stack.pop();
    a = stack.top();
    stack.pop();
    stack.push(sign(a, b));
    str++;
    if (*str != ' ' && *str != 0)
        return 1;
    return 0;
}

int rpn(const char *str) {
    std::stack<int> stack;
    int             err = 0;

    while (*str) {
        switch (get_rpn_type(*str)) {
        case RPN_NUM:
            stack.push(*str - '0');
            break;
        case RPN_MULT:
            err = rpn_sign(str, stack, rpn_mult);
            break;
        case RPN_DIV:
            err = rpn_sign(str, stack, rpn_div);
            break;
        case RPN_SUB:
            err = rpn_sign(str, stack, rpn_sub);
            break;
        case RPN_ADD:
            err = rpn_sign(str, stack, rpn_add);
            break;
        case RPN_MOD:
            err = rpn_sign(str, stack, rpn_mod);
            break;
        case RPN_SPACE:
            break;
        default:
            return 1;
        }
        if (err)
            return err;
        str++;
    }
    if (stack.size() != 1)
        return 1;
    std::cout << stack.top() << std::endl;
    return 0;
}

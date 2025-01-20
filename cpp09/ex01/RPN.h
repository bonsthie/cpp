#pragma once

#include <unordered_map>

enum rpn_type {
	RPN_NUM,
    RPN_MULT,
    RPN_DIV,
    RPN_SUB,
    RPN_ADD,
    RPN_MOD,
    RPN_SPACE,
	RPN_ERR,
};

void rpn(const char *str);

#pragma once

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

int rpn_mult(int nb1, int nb2);
int rpn_div(int nb1, int nb2);
int rpn_sub(int nb1, int nb2);
int rpn_add(int nb1, int nb2);
int rpn_mod(int nb1, int nb2);

int rpn(const char *str);

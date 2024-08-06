/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:50:48 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 14:51:15 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"
#include <iostream>

#ifndef __FALLTHROUGH
#  if defined(__GNUC__) && __GNUC__ >= 7
#		define __FALLTHROUGH __attribute__((fallthrough));
#  elif defined(__clang__) && __has_attribute(fallthrough)
#		define __FALLTHROUGH __attribute__((fallthrough));
#  else
#    define __FALLTHROUGH /* fallthrough */
#  endif
#endif

enum { DEBUG, INFO, WARNING, ERROR };

void Harl::complain(const std::string &level) const {
    static const std::string funcName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int                      i = 0;
    for (; i < 4; i++) {
        if (funcName[i] == level)
            break;
    }
    switch (i) {
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
    case DEBUG:
        _debug();
        __FALLTHROUGH
    case INFO:
        _info();
        __FALLTHROUGH
    case WARNING:
        _warning();
        __FALLTHROUGH
    case ERROR:
        _error();
    }
}

void Harl::_debug(void) const {
    std::cout << "[ DEBUG ] : I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
              << std::endl;
}

void Harl::_info(void) const {
    std::cout << "[ INFO ] : I cannot believe adding extra bacon costs more money. You didn’t put "
                 "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::_warning(void) const {
    std::cout << "[ WARNING ] : I think I deserve to have some extra bacon for free. I’ve been "
                 "coming for years whereas you started working here since last month."
              << std::endl;
}

void Harl::_error(void) const {
    std::cout << "[ ERROR ] : This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:52:19 by babonnet          #+#    #+#             */
/*   Updated: 2025/02/27 13:29:09 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>

int main(void) {
    const std::string  string = "HI THIS IS BRAIN";
    const std::string *stringPtr = &string;
    const std::string &stringRef = string;

    std::cout << "The memory address of the string variable : " << &string << std::endl;
    std::cout << "The memory address held by stringPtr      : " << stringPtr << std::endl;
    std::cout << "The memory address held by stringRef      : " << &stringRef << std::endl;

    std::cout << std::endl;

    std::cout << "The value of the string variable  : " << string << std::endl;
    std::cout << "The value pointed to by stringPtr : " << *stringPtr << std::endl;
    std::cout << "The value pointed to by stringRef : " << stringRef << std::endl;
}

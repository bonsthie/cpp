/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:28:52 by babonnet          #+#    #+#             */
/*   Updated: 2024/06/15 23:17:02 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.h"
#include <string>

#ifndef COLUMN_SIZE
#define COLUMN_SIZE 10
#endif

typedef unsigned char uint8_t;

class PhoneBook {
  private:
    void ADD(void);
    void SEARCH(void);
    void EXIT(void);

    Contact           _contact[8];
    uint8_t           _index : 3;
    const std::string _divider;

  public:
    PhoneBook(void);
	int executeCommand(const std::string &command);
};

bool readInput(std::string &input);

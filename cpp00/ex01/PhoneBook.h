/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:28:52 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/12 18:09:41 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.h"
#include <string>

#ifndef COLUMN_SIZE
#define COLUMN_SIZE 10
#endif

class PhoneBook {
  public:
    PhoneBook();
    void executeCommand(const std::string &command);

  private:
    void ADD(void);
    void SEARCH(void);
    void EXIT(void);

    struct contact    _contact[8];
    unsigned short    _index : 3;
    const std::string _divider;
};

std::string readInput();

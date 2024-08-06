/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:28:52 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 15:26:38 by bonsthie         ###   ########.fr       */
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
public:
  PhoneBook(void);
  int executeCommand(const std::string &command);

private:
  int ADD(void);
  int SEARCH(void);
  int EXIT(void);

  Contact _contact[8];
  uint8_t _index : 3;
  const std::string _divider;
};

bool readInput(std::string &input);

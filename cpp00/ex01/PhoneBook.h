/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:28:52 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/11 20:32:48 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.h"
#include <string>

#ifndef COLONNE_SIZE
# define COLONNE_SIZE 10
#endif

class PhoneBook {
public:
  PhoneBook();
  void executeCommand(const std::string &command);

private:
  void ADD(void);
  void SEARCH(void);
  void EXIT(void);

  struct contact _contact[8];
  unsigned short _index : 3;
};

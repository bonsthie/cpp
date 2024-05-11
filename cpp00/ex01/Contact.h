/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:11:59 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/11 18:13:13 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Contact.h"

class contact {
public:
  std::string getFirstName(void);
  std::string getLastName(void);
  std::string getNickname(void);
  std::string getPhoneNumber(void);
  std::string getDarkestSecret(void);

  void setFirstName(std::string newFirstName);
  void setLastName(std::string newLastName);
  void setNickname(std::string newNickname);
  void setPhoneNumber(std::string newPhoneNumber);
  void setDarkestSecret(std::string newDarkestSecret);

private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickname;
  std::string _phoneNumber;
  std::string _darkestSecret;
};

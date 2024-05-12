/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:11:59 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/12 18:07:53 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.h"
#include <string>

class contact {
  public:
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickname(void) const;
    std::string getPhoneNumber(void) const;
    std::string getDarkestSecret(void) const;

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

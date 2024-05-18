/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:21:28 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/18 11:54:52 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

class File {
  public:
    File(std::string filename);
    ~File(void);
    int  sed(const std::string &s1, const std::string &s2);
    bool is_open(void);

  private:
    std::string   _infileName;
    std::string   _outfileName;
    std::ofstream _outfile;
    std::string   _strfile;
    bool          _isOpen;
};

int sed(const std::string &file, const std::string &s1, const std::string &s2);

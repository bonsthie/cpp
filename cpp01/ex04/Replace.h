/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:21:28 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/17 15:18:52 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

class Replace {
  public:
    int sed(const std::string &file, const char *s1, const char *s2);

  private:
    std::ifstream _infile;
    std::string   _infileName;
    std::ofstream _outfile;
    std::string   _outfileName;
    std::string   _strfile;
    std::string   _s1;
    std::string   _s2;

    int _sedInput(void);
    void _sedOutput(void);
    void _sedReplace(void);
};

int sed(const std::string &file, const char *s1, const char *s2);

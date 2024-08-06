/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:21:28 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 14:42:42 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>

class File : public std::ifstream {
  public:
    File(const std::string &filename);
    ~File(void);
    int  sed(const std::string &s1, const std::string &s2);

  private:
    std::string   _infileName;
    std::string   _outfileName;
    std::ofstream _outfile;
    std::string   _strfile;
    bool          _isOpen;
};

int sed(const std::string &file, const std::string &s1, const std::string &s2);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:27:09 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 14:51:17 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.h"
#include <iostream>
#include <sstream>

File::File(const std::string &filename)
    : _infileName(filename),
      _isOpen(true) {
	_outfileName = filename + ".replace";
    
    this->open(filename.c_str());
    if (!this->is_open()) {
        std::cerr << "Could not open file " + filename << std::endl;
        _isOpen = false;
        return;
    }

    std::ostringstream contentStream;
    contentStream << this->rdbuf();
    _strfile = contentStream.str();
    this->close();
}

File::~File(void) {
    std::string fileOutput;

    std::ofstream outfile(_outfileName.c_str());
    if (!outfile.is_open())
        std::cerr << "Could not create the outfile" << std::endl;
    else {
        outfile << _strfile;
        _outfile.close();
    }
}

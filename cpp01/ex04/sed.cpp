/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:05:46 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/18 12:02:00 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.h"

File::File(std::string filename)
    : _infileName(filename),
      _outfile(_infileName + ".replace"),
      _isOpen(true) {
    std::ifstream infile;

    infile.open(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Could not open file " + filename << std::endl;
        _isOpen = false;
        return;
    }

    std::ostringstream contentStream;
    contentStream << infile.rdbuf();
    _strfile = contentStream.str();
    infile.close();
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

int File::sed(const std::string &s1, const std::string &s2) {
    if (s1.empty() || s2.empty()) {
        std::cerr << "invalid parameter" << std::endl;
        return (1);
    }
    size_t pos = 0;

    pos = _strfile.find(s1, pos);
    while (pos < _strfile.length()) {
        _strfile.erase(pos, s1.length());
        _strfile.insert(pos, s2);
        pos = _strfile.find(s1, pos);
    }
    return (0);
}

bool File::is_open(void) { return (_isOpen); }

int sed(const std::string &file, const std::string &s1, const std::string &s2) {
    File input(file);
    if (!input.is_open())
        return (1);
    return (input.sed(s1, s2));
}

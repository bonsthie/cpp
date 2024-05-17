/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:05:46 by babonnet          #+#    #+#             */
/*   Updated: 2024/05/17 16:10:32 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.h"

void Replace::_sedReplace(void) {
    const size_t len = _strfile.length();
    const size_t len_s1 = _s1.length();
    size_t       pos = 0;

    pos = _strfile.find(_s1, pos);
    while (pos < len) {
        _strfile.erase(pos, len_s1);
        _strfile.insert(pos, _s2);
        pos = _strfile.find(_s1, pos);
    }
    std::cout << _strfile << std::endl;
}

int Replace::_sedInput(void) {
    _infile.open(_infileName.c_str());
    if (!_infile.is_open()) {
        std::cerr << "Could not open file " + _infileName << std::endl;
        return (1);
    }
    std::ostringstream contentStream;
    contentStream << _infile.rdbuf();
    _strfile = contentStream.str();
    return (0);
}

void Replace::_sedOutput(void) {
    std::string fileOutput;

    std::ofstream outfile(_outfileName.c_str());
    if (!outfile.is_open())
        std::cerr << "Could not create the outfile" << std::endl;
    else {
        outfile << _strfile;
        _outfile.close();
    }
    _infile.close();
}

int Replace::sed(const std::string &file, const char *s1, const char *s2) {

    if (!s1 || !s2 || !*s1 || !*s2) {
        std::cerr << "invalid parameter" << std::endl;
        return (1);
    }
    _infileName = file;
    if (_sedInput())
        return (1);
    _s1 = s1;
    _s2 = s2;
    _sedReplace();
    _outfileName = _infileName + ".replace";
    _sedOutput();
    return (0);
}

int sed(const std::string &file, const char *s1, const char *s2) {
    Replace replace;
    return (replace.sed(file, s1, s2));
}

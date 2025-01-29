// Components for manipulating sequences of characters -*- C++ -*-
#pragma once

#include <regex.h>
#include <string>
#include <vector>

typedef std::vector<std::string> FTregMatch;
typedef FTregMatch::iterator FTregMatchIt;

class FTregex {
  public:
    FTregex(const std::string &pattern);
    FTregex(const char *pattern);
    ~FTregex();

    FTregMatch match(const std::string &input) const;

	int captureGroupSize(void) const;

    class regex_err : public std::exception {
      public:
        regex_err(int status, const regex_t &regex);
		virtual ~regex_err() throw();
        virtual const char *what() const throw();

      private:
        std::string _msg;
    };

  private:
    regex_t _regex;
};

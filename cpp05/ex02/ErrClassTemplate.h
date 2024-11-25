#pragma once

#define ERR_CLASS(err_class)                                                   \
    class err_class : public std::exception {                                  \
      public:                                                                  \
        virtual const char *what() const throw();                              \
    };

#define ERR_WHAT(base_class, err_class, err_msg)                               \
    const char *base_class::err_class::what() const throw() { return err_msg; }

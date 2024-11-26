#include "Base.h"
#include "log.h"
#include <immintrin.h>
#include <iostream>

Base::~Base(){LOG("destructor base")}

Base *generate(void) {
  unsigned int random_value;
  _rdrand32_step(&random_value);

  switch (random_value % 3) {
  case 0:
	  std::cout << "create a A class" << std::endl;
    return new A;
  case 1:
	  std::cout << "create a B class" << std::endl;
    return new B;
  default:
	  std::cout << "create a C class" << std::endl;
    return new C;
  }
}


void identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "this is A class" << std::endl;
	else if(dynamic_cast<B *>(p))
		std::cout << "this is B class" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "this is C class" << std::endl;
	else
		std::cout << "this is any of those class" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "this is A class" << std::endl;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "this is B class" << std::endl;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "this is C class" << std::endl;
	} catch (...) {}
	std::cout << "this is any of those class" << std::endl;
}

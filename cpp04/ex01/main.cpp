#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include <iostream>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define NEW_IDEAR ("idea_" TOSTRING(__COUNTER__))

int main() {
  std::cout << "---- delete test----" << std::endl;
  {
    Animal *zoo[100];

    for (int i = 0; i < 50; i++) {
      zoo[i] = new Cat();
    }

    for (int i = 50; i < 100; i++) {
      zoo[i] = new Dog();
    }

    for (int i = 0; i < 100; i++) {
      delete zoo[i];
    }
  }
  std::cout << "---- copy test----" << std::endl;
  {
    Cat *a = new Cat();
    for (int i = 0; i < 10; i++) {
      std::string idea = "idea_" + std::string(1, '0' + i);
      a->setBrainIdear(idea, i);
      std::cout << i << " " << a->getBrainIdear(i) << std::endl;
    }
    std::cout << std::endl;
    Cat b;
    b = *a;
    for (int i = 0; i < 10; i++)
      std::cout << i << " " << b.getBrainIdear(i) << std::endl;
    delete a;
  }
}

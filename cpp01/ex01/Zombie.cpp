/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bonsthie <bonsthie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:26:17 by babonnet          #+#    #+#             */
/*   Updated: 2024/08/06 14:07:37 by bonsthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>
#include <ostream>

Zombie::Zombie(const std::string &name) : _name(name) {
#ifdef VERBOSE
  std::cout << "Zombie Constructor by name: " << name << std::endl;
#endif
}

Zombie::Zombie() {
#ifdef VERBOSE
  std::cout << "Zombie Constructor default" << std::endl;
#endif
}

Zombie::~Zombie() {
#ifdef VERBOSE
  std::cout << "Zombie destructor of " << _name << std::endl;
#endif
}

void Zombie::announce(void) const {
  std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}


// for the lol because why not!
void *Zombie::operator new[](size_t size, const std::string &name) {
  void *p = ::operator new(size * sizeof(Zombie) + sizeof(size_t));
  if (!p)
    return (p);

  size_t *Nsize = static_cast<size_t *>(p);
  *Nsize = size;
  (void)name;
  Zombie *start = static_cast<Zombie *>(static_cast<void *>(Nsize + 1));

  for (size_t i = 0; i < size; i++) {
    ::new (&start[i]) Zombie(name);
  }
  return (start);
}

void Zombie::operator delete[](void *p) {
  if (!p)
    return;

  Zombie *start = static_cast<Zombie *>(p);
  size_t *size_ptr = reinterpret_cast<size_t *>(start) - 1;
  size_t size = *size_ptr;

  for (size_t i = 0; i < size; i++) {
    start[i].~Zombie();
  }
  ::operator delete(size_ptr);
}

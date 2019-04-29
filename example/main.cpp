#include <iostream>
#include <pqrs/cf/boolean.hpp>

int main(void) {
  if (auto b = pqrs::cf::make_bool(pqrs::cf::make_cf_boolean(true))) {
    std::cout << *b << std::endl;
  }

  return 0;
}

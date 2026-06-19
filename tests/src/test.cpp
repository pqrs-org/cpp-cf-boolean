#include <boost/ut.hpp>
#include <pqrs/cf/boolean.hpp>

int main() {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "make_cf_boolean"_test = [] {
    expect(pqrs::cf::make_cf_boolean(true) == kCFBooleanTrue);
    expect(pqrs::cf::make_cf_boolean(false) == kCFBooleanFalse);
  };

  "make_bool"_test = [] {
    expect(pqrs::cf::make_bool(kCFBooleanTrue) == std::optional<bool>{true});
    expect(pqrs::cf::make_bool(kCFBooleanFalse) == std::optional<bool>{false});
    expect(pqrs::cf::make_bool(nullptr) == std::nullopt);
    expect(pqrs::cf::make_bool(CFSTR("true")) == std::nullopt);
  };

  return 0;
}

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <pqrs/cf/boolean.hpp>

TEST_CASE("make_cf_boolean") {
  REQUIRE(pqrs::cf::make_cf_boolean(true) == kCFBooleanTrue);
  REQUIRE(pqrs::cf::make_cf_boolean(false) == kCFBooleanFalse);
}

TEST_CASE("make_bool") {
  REQUIRE(pqrs::cf::make_bool(kCFBooleanTrue) != std::nullopt);
  REQUIRE(*pqrs::cf::make_bool(kCFBooleanTrue) == true);

  REQUIRE(pqrs::cf::make_bool(kCFBooleanFalse) != std::nullopt);
  REQUIRE(*pqrs::cf::make_bool(kCFBooleanFalse) == false);

  REQUIRE(pqrs::cf::make_bool(nullptr) == std::nullopt);
  REQUIRE(pqrs::cf::make_bool(CFSTR("true")) == std::nullopt);
}

/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "test_constants.h"

namespace tutorial {

const testConstants g_test_constants;

testConstants::testConstants() {
  INT32CONSTANT = 9853;

  MAPCONSTANT.insert(std::make_pair("hello", "world"));
  MAPCONSTANT.insert(std::make_pair("goodnight", "moon"));

}

} // namespace


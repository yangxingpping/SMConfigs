#ifndef FOO_BAR_HPP_
#define FOO_BAR_HPP_

#include <Baz.hpp>
#include <BAR_EXPORT.h>
#include "spdlog/spdlog.h"

namespace foo {

class BAR_EXPORT Bar {
 public:
  static void say() {
    Baz::say();
#if (FOO_BAR_DEBUG)
    const char* m = "Bar.hpp (Debug)";
#else
    const char* m = "Bar.hpp (Not debug)";
#endif
    SPDLOG_INFO("{}", m);
    cpp_say();
  }

 private:
  static void cpp_say();
};

}

#endif // FOO_BAR_HPP_

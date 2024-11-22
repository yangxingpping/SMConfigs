#include "spdlog/spdlog.h"

namespace foo {

class Baz {
 public:
  static void say() {
#if (FOO_BAZ_DEBUG)
    const char* m = "Baz.hpp (Debug)";
#else
    const char* m = "Baz.hpp (Not debug)";
#endif
    SPDLOG_INFO(m);
    cpp_say();
  }

 private:
  static void cpp_say();
};

} // namespace foo


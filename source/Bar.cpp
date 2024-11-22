#include <Bar.hpp>
#include "spdlog/spdlog.h"
namespace foo {

void Bar::cpp_say() {
#if (FOO_BAR_DEBUG)
  const char* m = "Bar.cpp (Debug)";
#else
  const char* m = "Bar.cpp (Not debug)";
#endif
  SPDLOG_INFO(m);
}

} // namespace foo

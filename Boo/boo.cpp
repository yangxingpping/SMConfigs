#include <Bar.hpp>
#include "spdlog/spdlog.h"

int main()
{
  SPDLOG_INFO("Hello, Boo!");
  foo::Bar::say();
  return 0;
}

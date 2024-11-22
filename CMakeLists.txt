cmake_minimum_required(VERSION 3.25)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

project(youngCMake)

find_package(spdlog CONFIG REQUIRED)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
  if(PROJECT_IS_TOP_LEVEL)
    set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
  endif()
    add_definitions(-DOTL_ODBC)
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Linux")
  SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wunused-function -Wunused-local-typedefs  -g -ggdb")
  SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
  add_definitions(-DASIO_HAS_IO_URING)
  include_directories(/usr/local/include /usr/include/postgresql)
  include_directories("$ENV{VCPKG_ROOT}/installed/x64-linux/include")
  link_directories(/usr/local/lib "$ENV{VCPKG_ROOT}/installed/x64-linux/lib")
  link_libraries(ssl pthread crypto uring z)
  add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fpermissive>)
  add_link_options(-Wl,--no-as-needed)
  add_definitions(-DOTL_ODBC_UNIX -DOS_LINUX)
ELSEIF(CMAKE_SYSTEM_NAME MATCHES "Darwin")
  include_directories(/usr/local/include)
  include_directories("$ENV{VCPKG_ROOT}/installed/x64-osx/include")
  link_directories(/usr/local/lib)
  add_definitions(-DOS_DARWIN)
  set(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS}  -Wno-unused-value -pedantic")
ENDIF(CMAKE_SYSTEM_NAME MATCHES "Windows")

set(CMAKE_DEBUG_POSTFIX d)

enable_testing()

# Monolithic version
add_subdirectory(source)
add_subdirectory(Boo)

project(ConanBatteries C CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

set(CMAKE_CXX_STANDARD 11)
add_executable(batteries src/test_expat.c main.cpp)
conan_target_link_libraries(batteries)
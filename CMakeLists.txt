cmake_minimum_required(VERSION 3.10)
project(WeatherApp)

set(CMAKE_CXX_STANDARD 17)

if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake CACHE STRING "")
endif()

find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(WeatherApp src/main.cpp)
target_link_libraries(WeatherApp PRIVATE cpr::cpr nlohmann_json::nlohmann_json)
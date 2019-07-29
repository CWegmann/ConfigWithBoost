cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(ConfigWithBoost LANGUAGES CXX)

add_subdirectory(3rd_party) # I separated the dependency/-ies into a separate directory
add_subdirectory(ConfigParser)
add_subdirectory(Consumer)

add_executable(
    ConfigWithBoost
    main.cpp)

target_link_libraries(
    ConfigWithBoost
    ConfigParser
    Consumer
)

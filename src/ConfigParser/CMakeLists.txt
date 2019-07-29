add_library(ConfigParser
    ConfigParser.cpp
    )

target_link_libraries(
    ConfigParser
    PUBLIC 3rd_party
    )

target_include_directories(
    ConfigParser
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    )

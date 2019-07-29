add_library(Consumer
    Consumer.cpp
    )

target_link_libraries(
    Consumer
    PUBLIC 3rd_party
    )

target_include_directories(
    Consumer
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    )

set( Boost_USE_STATIC_LIBS ON )

find_package(Boost 1.70 COMPONENTS program_options REQUIRED)

add_library(3rd_party INTERFACE)

target_link_libraries(3rd_party INTERFACE Boost::program_options)

#you have to adjust this line; with a bit of luck you can leave it out on Linux ;-)
target_include_directories(3rd_party INTERFACE C:/boost/boost_1_70_0/ C:/boost/boost_1_70_0/boost)

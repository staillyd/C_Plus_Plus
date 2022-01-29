project(Multiproess)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
add_definitions("-Wall -g")

include_directories(${PROJECT_SOURCE_DIR})

add_executable(producer_consumer producer_consumer.cpp )
target_link_libraries(producer_consumer pthread)
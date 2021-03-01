cmake_minimum_required(VERSION 3.17)
project(Reference)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 3.4)
message("[OPENCV] :   ${OpenCV_INCLUDE_DIRS}")
message("[OPENCV] : ${OpenCV_LIBRARIES}")

include_directories(
        ${OpenCV_INCLUDE_DIRS}
)

add_executable(Reference main.cpp)
target_link_libraries(Reference  ${OpenCV_LIBS}   ${OpenCV_LIBRARIES})

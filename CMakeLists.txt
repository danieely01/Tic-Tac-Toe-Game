cmake_minimum_required(VERSION 3.30.5)
project(CLionGraphicsKit)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_library(graphics graphics.cpp)

include_directories(include)
link_directories(lib)

target_link_libraries( graphics SDL2 SDL2.dll SDL2main SDL2_ttf SDL2_ttf.dll)


add_executable(CLionGraphicsKit main.cpp
        listbox.cpp
        stepper.cpp
        widgets.cpp
        Mezo.cpp
        Mezo.hpp
        Jatekmester.cpp
        Jatekmester.hpp)
target_link_libraries(CLionGraphicsKit graphics)

add_custom_command(TARGET CLionGraphicsKit POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/SDL2.dll"
        "${PROJECT_SOURCE_DIR}/SDL2_ttf.dll"
        "${PROJECT_SOURCE_DIR}/libfreetype-6.dll"
        "${PROJECT_SOURCE_DIR}/zlib1.dll"
        "${PROJECT_SOURCE_DIR}/LiberationSans-Regular.ttf"
        $<TARGET_FILE_DIR:CLionGraphicsKit>
)

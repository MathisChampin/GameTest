cmake_minimum_required(VERSION 3.15)
project(GreenCity)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ENGINE_DIR "${CMAKE_SOURCE_DIR}/engine")
set(GAME_DIR "${CMAKE_SOURCE_DIR}/game")

file(GLOB_RECURSE ENGINE_SRC ${ENGINE_DIR}/*.cpp)
file(GLOB_RECURSE GAME_SRC ${GAME_DIR}/*.cpp)

set(MAIN_SRC "${CMAKE_SOURCE_DIR}/main.cpp")

add_executable(GreenCity
    ${MAIN_SRC}
    ${ENGINE_SRC}
    ${GAME_SRC}
)

file(GLOB_RECURSE TEST_SRC tests/*.cpp)

add_executable(Tests 
    ${ENGINE_SRC}
    ${GAME_SRC}
    ${TEST_SRC}
)

target_include_directories(Tests PRIVATE
    /opt/homebrew/include
    ${ENGINE_DIR}
    ${GAME_DIR}
)

target_link_directories(Tests PRIVATE
    /opt/homebrew/lib
)

target_link_libraries(Tests
    criterion
    sfml-graphics
    sfml-window
    sfml-system
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(GreenCity
    sfml-graphics
    sfml-window
    sfml-system
)

target_include_directories(GreenCity PRIVATE
    ${ENGINE_DIR}
    ${GAME_DIR}
)

configure_file(assets/fonts/Oswald-VariableFont_wght.ttf assets/fonts/Oswald-VariableFont_wght.ttf COPYONLY)
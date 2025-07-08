cmake_minimum_required(VERSION 3.15)
project(GreenCity)

set(CMAKE_CXX_STANDARD 17)

# Inclure tous les fichiers sources
file(GLOB_RECURSE SRC
    "engine/*.cpp"
    "game/*.cpp"
)

add_executable(GreenCityWars ${SRC})

# Lier SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(GreenCityWars sfml-graphics sfml-window sfml-system)

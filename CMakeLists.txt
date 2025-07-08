cmake_minimum_required(VERSION 3.15)
project(GreenCity)

set(CMAKE_CXX_STANDARD 17)

# Récupère les fichiers source
file(GLOB_RECURSE SRC
    "engine/*.cpp"
    "game/*.cpp"
)

add_executable(GreenCity ${SRC})

# Lier SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(GreenCity sfml-graphics sfml-window sfml-system)

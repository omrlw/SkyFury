cmake_minimum_required(VERSION 3.26)
project(SkyFury)
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(SkyFury Source/Main.cpp
        Source/Game.cpp
        Include/Graphics_SFML.hpp
        Include/ToStrings.hpp
        Include/ToStrings.inl
)

target_link_libraries(SkyFury sfml-graphics)
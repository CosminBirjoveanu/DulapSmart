cmake_minimum_required(VERSION 3.17)
project(SmartDrobe)

set(CMAKE_CXX_STANDARD 17)

include_directories(Interface
        Entities
        Repositories
        Services
        )

find_package(Threads REQUIRED)

include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.9.1)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(SmartDrobe Main/main.cpp Entities/Consumable.cpp Entities/Consumable.h)

target_link_libraries(SmartDrobe PRIVATE Threads::Threads -lpistache PRIVATE nlohmann_json::nlohmann_json)
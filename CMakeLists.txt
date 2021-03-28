cmake_minimum_required(VERSION 3.17)
project(SmartDrobe)

set(CMAKE_CXX_STANDARD 17)

include_directories(Interface
        Data/Entities
        Data/Repositories
        Services
        )

find_package(Threads REQUIRED)

add_executable(SmartDrobe Main/main.cpp Services/Services.h Services/Services.cpp)

target_link_libraries(SmartDrobe PRIVATE Threads::Threads -lpistache)
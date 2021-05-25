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

add_executable(SmartDrobe Main/main.cpp Entities/Consumable.cpp Entities/Consumable.h
        Entities/Haina.cpp
        Entities/Haina.h
        Entities/Umeras.cpp
        Entities/Umeras.h
        Interface/Interface.cpp
        Interface/Interface.h
        Services/DulapManager.cpp
        Services/DulapManager.h
        Services/HaineListener.cpp
        Services/HaineListener.h
        Controller/Server.cpp
        Controller/Server.h
        Services/NotificationManager.cpp
        Services/NotificationManager.h
        Services/Logger.cpp
        Services/Logger.h
        Services/ProfilDulap.cpp
        Services/ProfilDulap.h
        Services/RequestWrapper.cpp
        Services/RequestWrapper.h
        Services/SearchEngine.cpp
        Services/SearchEngine.h
        Services/Services.cpp
        Services/Services.h)

target_link_libraries(SmartDrobe PRIVATE curl Threads::Threads -lpistache PRIVATE nlohmann_json::nlohmann_json)

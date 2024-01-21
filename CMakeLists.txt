cmake_minimum_required(VERSION 3.6.2)

set(PROJECT_NAME Calc_for_ele_project_cmake)

project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)

if(WIN32)
    set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /W3 /GR /EHsc /std:c++17")
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd /Zi /Ob0 /Od /RTC1 /std:c++17")

    message("Win settings chosen...")
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -std=c++17 -Wall")

    message("Mac settings chosen...")
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")
    set(CMAKE_CXX_FLAGS_DEBUG "-g -std=c++17 -Wall")

    message("Linux settings chosen...")
endif()

# Inform CMake where the header files are
include_directories(include)

# Explicitly list resource files
set(SOURCES 
    "./src/Calc_for_ele_project.cpp" 
    "./src/Calc_for_ele_projectDlg.cpp" 
    "./src/pch.cpp"
    "./src/Conversions.cpp"
)

set(HEADERS 
    "./include/Calc_for_ele_project.h" 
    "./include/Calc_for_ele_projectDlg.h" 
    "./include/framework.h" 
    "./include/pch.h"
    "./include/targetver.h"
)

set(RESOURCES 
    "./res/Calcforeleproject.rc" 
    "./res/resource.h" 
)

# Create executable
add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${HEADERS} ${RESOURCES})

# Set the default project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")


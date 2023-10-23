cmake_minimum_required(VERSION 3.16)



# ========================
#  = Project properties = 
# ========================

project(MyProject VERSION 1.0.0 LANGUAGES C CXX)



# ========================
#  = Project executable =
# ========================

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/algorithm.c
)

target_include_directories(${PROJECT_NAME} PRIVATE include)    # Add the include directory to the project

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)     # Use C++17

set_target_properties(${PROJECT_NAME} PROPERTIES                # Set the output directory to the build directory
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}
    RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_BINARY_DIR}
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_BINARY_DIR}
)


# =======================
#  = cppgfx dependency =
# =======================

include(cmake/cppgfx.cmake)                                     # Retrieve the cppgfx library

target_link_libraries(${PROJECT_NAME} PRIVATE cppgfx)           # Link to the cppgfx library


# ===========================================
#  = Internal helper to run the executable =
# ===========================================

file(WRITE ${CMAKE_BINARY_DIR}/run.bat
    "@echo off\n"
    "%~dp0${PROJECT_NAME}.exe\n"
)
file(WRITE ${CMAKE_BINARY_DIR}/run.sh
    "#!/bin/bash\n"
    "./${PROJECT_NAME}\n"
)
execute_process(COMMAND chmod +x ${CMAKE_BINARY_DIR}/run.sh)

cmake_minimum_required(VERSION 3.16)



# ========================
#  = Project properties = 
# ========================

project(MyProject VERSION 1.0.0 LANGUAGES C CXX)



# =======================
#  = cppgfx dependency =
# =======================

include(cmake/cppgfx.cmake)



# ========================
#  = Project executable =
# ========================

add_executable(${PROJECT_NAME} 
    src/main.cpp
)

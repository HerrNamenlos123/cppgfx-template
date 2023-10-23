
include(FetchContent)

message(STATUS "Fetching cppgfx")
FetchContent_Declare(cppgfx
    GIT_REPOSITORY https://github.com/HerrNamenlos123/cppgfx.git
    GIT_TAG        main
)
FetchContent_MakeAvailable(cppgfx)

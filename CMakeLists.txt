cmake_minimum_required(VERSION 3.16)

project("cpp-project-template" VERSION 1.0.0 LANGUAGES CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD                17)
set(CMAKE_CXX_STANDARD_REQUIRED       ON)
set(CMAKE_CXX_EXTENSIONS              OFF)
set(CMAKE_CXX_EXPORT_COMPILE_COMMANDS ON)

# Options
option(ENABLE_WARNINGS     "Enable to add warnings to a target."         OFF)
option(ENABLE_TESTING      "Enable a Unit Testing build."                OFF)
option(ENABLE_COVERAGE     "Enable a Code Coverage build."               OFF)
option(ENABLE_CLANG_TIDY   "Enable to add clang-tidy. (static analysis)" OFF)
option(ENABLE_CLANG_FORMAT "Enable to add clang-format. (formatting)"    OFF)
option(ENABLE_VALGRING     "Enable to add valgrind. (memory leak check)" OFF)

### CMAKE MODULES

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(FetchContent)
include(Warnings)

if(ENABLE_TESTING)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.12.0
        GIT_SHALLOW TRUE
        )
    FetchContent_MakeAvailable(googletest)
endif()

if(ENABLE_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()

if(ENABLE_CLANG_TIDY)
    include(clang-tidy)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif()

# if(ENABLE_CLANG_FORMAT)
#     include(clang-format)
# endif()

### EXTERNAL LIBRARIES

### SUBDIRECTORIES

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)

### INSTALL TARGETS


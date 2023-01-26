# Sources and Headers
set(LIBRARY_SOURCES
    "division.cpp")
set(LIBRARY_HEADERS
    "division.h")
set(LIBRARY_INCLUDES
    "./")

# division Library
set(LIBRARY_NAME "division")

add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})

target_include_directories(${LIBRARY_NAME} PUBLIC
    ${LIBRARY_INCLUDES})

# target_link_libraries(${LIBRARY_NAME} PRIVATE
#     someExternalLibrary)

if(${ENABLE_WARNINGS})
    target_set_warnings(TARGET ${LIBRARY_NAME} ENABLE ON AS_ERROR OFF)
endif()
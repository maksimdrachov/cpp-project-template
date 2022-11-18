if(ENABLE_TESTING)
    enable_testing()

    set(TEST_MAIN "unit_tests")
    set(TEST_SOURCES "main.cpp")

    add_executable(${TEST_MAIN}
      ${TEST_SOURCES})
    
    target_link_libraries(${TEST_MAIN} 
        PUBLIC
            division
        PRIVATE
            GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(${TEST_MAIN})

    if(${ENABLE_WARNINGS})
        target_set_warning(TARGET ${TEST_MAIN} ENABLE ON AS_ERROR OFF)
    endif()

    if(ENABLE_COVERAGE)
        set(COVERAGE_MAIN "coverage")
        set(COVERAGE_EXCLUDES
            "${PROJECT_SOURCE_DIR}/app/*"
            "${PROJECT_SOURCE_DIR}/cmake/*"
            "${PROJECT_SOURCE_DIR}/docs/*"
            "${PROJECT_SOURCE_DIR}/external/*"
            "${PROJECT_SOURCE_DIR}/tests/*"
            "*/gtest/*"
            "/usr/include/*"
            )
        setup_target_for_coverage_lcov(
            NAME ${COVERAGE_MAIN}
            EXECUTABLE ${TEST_MAIN}
            DEPENDENCIES ${TEST_MAIN})
    endif()

endif()
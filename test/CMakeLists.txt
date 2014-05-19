# libmpk unit tests
# Copyright 2013 Josef Raschen <josef@raschen.org>
cmake_minimum_required(VERSION 2.8)

message("Gtest inc dirs: ${GTEST_INCLUDE_DIRS}")
include_directories(
    ${PROJECT_SOURCE_DIR}/ext/gtest/include
#    ${LIBMPK_INC_DIR}
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

link_directories(
    ${LIBMPK_LIB_DIR}
)

set(MPK_TEST_SRC
    main.cpp
)

set(MPK_TEST_LIBS
    mpk
    gtest
    gtest_main
)

add_executable(libmpk-test ${MPK_TEST_SRC})
target_link_libraries(libmpk-test ${MPK_TEST_LIBS})

add_custom_target(test libmpk-test)

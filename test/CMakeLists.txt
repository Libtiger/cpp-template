set(GTEST_DIR ~/libs/gtest)
set(GTEST_INCLUDE_DIR ${GTEST_DIR}/include)
set(GTEST_LIBRATY_DIR ${GTEST_DIR}/lib)

link_directories(${GTEST_LIBRATY_DIR})

add_executable(mytest test.cpp)
target_include_directories(mytest PUBLIC ${GTEST_INCLUDE_DIR})
target_link_libraries(mytest PUBLIC gtest gtest_main pthread)

add_test(MyTest mytest COMMAND mytest)


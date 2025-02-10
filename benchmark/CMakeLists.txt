set(BENCHMARK_DIR ~/libs/benchmark)
set(BENCHMARK_INCLUDE_DIR ${BENCHMARK_DIR}/include)
set(BENCHMARK_LIBRARY_DIR ${BENCHMARK_DIR}/lib)

link_directories(${BENCHMARK_LIBRARY_DIR})

add_executable(benchmark_sample benchmark_sample.cpp)
target_include_directories(benchmark_sample PUBLIC ${BENCHMARK_INCLUDE_DIR})
target_link_libraries(benchmark_sample PUBLIC benchmark benchmark_main pthread)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(TARGET main)
add_executable(${TARGET} main.cpp)
target_link_libraries(${TARGET} PUBLIC lib)

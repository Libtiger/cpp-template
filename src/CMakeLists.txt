file(GLOB_RECURSE SRC_LIST *.cpp)

set(SPDLOG_DIR ~/libs/spdlog)
set(SPDLOG_INCLUDE_DIR ${SPDLOG_DIR}/include/)
set(SPDLOG_LIBRARY ${SPDLOG_DIR}/lib/libspdlog.a)

set(LIB_NAME lib)

add_library(${LIB_NAME} SHARED ${SRC_LIST})

target_include_directories(${LIB_NAME} PUBLIC
    ${SPDLOG_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/include)
target_link_directories(${LIB_NAME} PUBLIC
    ${SPDLOG_LIBRARY})

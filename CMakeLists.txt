cmake_minimum_required(VERSION 3.19)

project(MBProto VERSION 0.1)

find_package(Boost REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(SQLite3)

if(NOT ${SQLite3_FOUND})
    find_package(Threads REQUIRED)
    set(SQLite3_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sqlite3)
    set(SQLite3_INCLUDE_DIRS ${SQLite3_DIR})
    set(SQLite3_SOURCES
        ${SQLite3_DIR}/shell.c
        ${SQLite3_DIR}/sqlite3.c
    )
    add_library(SQLite3 ${SQLite3_SOURCES})
    target_link_libraries(SQLite3 ${CMAKE_THREAD_LIBS_INIT})
    set(SQLite3_LIBRARIES SQLite3)
endif()

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(MBProto_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(ASSETS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/parser/assets)
set(SOURCES
    ${SOURCE_DIR}/tl/bare.cpp
    ${SOURCE_DIR}/tl/functions.cpp
    ${SOURCE_DIR}/tl/TLObject.cpp
    ${SOURCE_DIR}/tl/types.cpp
    ${SOURCE_DIR}/transports/tcp.cpp
    ${SOURCE_DIR}/transports/Transport.cpp
    ${SOURCE_DIR}/utils/packing.cpp
    ${SOURCE_DIR}/utils/streams.cpp
    ${SOURCE_DIR}/AuthKey.cpp
    ${SOURCE_DIR}/Client.cpp
    ${SOURCE_DIR}/Connection.cpp
    ${SOURCE_DIR}/Session.cpp
    ${SOURCE_DIR}/Storage.cpp
)
set(PARSER_OUTPUTS
    ${MBProto_INCLUDE_DIR}/tl/types.h
    ${SOURCE_DIR}/tl/types.cpp
    ${MBProto_INCLUDE_DIR}/tl/functions.h
    ${SOURCE_DIR}/tl/functions.cpp
    ${SOURCE_DIR}/tl/TLObject.cpp
)
set(PARSER_DEPENDENCIES
    ${ASSETS_DIR}/mtproto_api.tl
    ${ASSETS_DIR}/telegram_api.tl
)
set(INCLUDE_DIRS
    ${MBProto_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
    ${OPENSSL_INCLUDE_DIR}
    ${SQLite3_INCLUDE_DIRS}
)
set(LIBRARIES
    ${CMAKE_DL_LIBS}
    ${SQLite3_LIBRARIES}
    ${OPENSSL_CRYPTO_LIBRARIES}
)

add_subdirectory(parser)
add_custom_command(
    OUTPUT ${PARSER_OUTPUTS}
    COMMAND parser --types --header
    COMMAND parser --types --source
    COMMAND parser --functions --header
    COMMAND parser --functions --source
    COMMAND parser --tl_object
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS ${PARSER_DEPENDENCIES}
)

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(MBProto PUBLIC ${INCLUDE_DIRS})
target_link_libraries(MBProto ${LIBRARIES})

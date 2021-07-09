cmake_minimum_required(VERSION 3.14)

project(MBProto VERSION 0.0.1)

find_package(Threads REQUIRED)
find_package(SQLite3)

add_library(MBProto
	src/transports/TCP.cpp
	src/transports/Transport.cpp
	src/Client.cpp
	src/Connection.cpp
	src/Storage.cpp
	src/Session.cpp
)
target_include_directories(MBProto PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(MBProto ${CMAKE_THREAD_LIBS_INIT})

if(SQLITE3_FOUND)
	target_link_libraries (tutorial ${SQLITE3_LIBRARIES})
	include_directories(${SQLITE3_INCLUDE_DIRS})
else()
	add_subdirectory(SQLite3)
	target_link_libraries(MBProto SQLite3)
endif()

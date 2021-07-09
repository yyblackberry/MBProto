cmake_minimum_required(VERSION 3.14)

project(SQLite3 VERSION 3.36.0)

add_library(SQLite3
	src/shell.c
	src/sqlite3.c
)
target_include_directories(SQLite3 PUBLIC include)

cmake_minimum_required( VERSION 3.7 )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

project( Networking )

option( BUILD_TESTS "Build test programs" OFF )

add_subdirectory( src )

if( BUILD_TESTS )
	add_subdirectory( test )
endif( BUILD_TESTS )

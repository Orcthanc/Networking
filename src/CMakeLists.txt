project( NetworkingLib )

file( GLOB_RECURSE ${PROJECT_NAME}_SOURCES "*.cpp" )

add_library( ${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES} )

target_include_directories( NetworkingLib PUBLIC "." "../include" )

project( NetworkingTest )

add_executable( ${PROJECT_NAME} main.cpp )
target_link_libraries( ${PROJECT_NAME} PRIVATE NetworkingLib )
target_include_directories( ${PROJECT_NAME} PRIVATE NetworkingLib )

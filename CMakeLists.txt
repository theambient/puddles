
cmake_minimum_required(VERSION 2.8)

project(puddles)

# find_package(Boost COMPONENTS filesystem program_options system regex thread REQUIRED)

list(APPEND CMAKE_CXX_FLAGS -std=c++11)

file(GLOB_RECURSE SOURCES "source/*")

set(LIBS
	${Boost_LIBRARIES}
)

add_executable( puddles
	${SOURCES}
)

target_include_directories(puddles PUBLIC ${LIBS})
target_include_directories(puddles PUBLIC source/ )

target_link_libraries(puddles ${Boost_LIBRARIES})

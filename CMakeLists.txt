
cmake_minimum_required(VERSION 3.2)

project(puddles)

# find_package(Boost COMPONENTS filesystem program_options system regex thread REQUIRED)

list(APPEND CMAKE_CXX_FLAGS -std=c++11)

file(GLOB_RECURSE SOURCES "source/*")

set(LIBS
	${Boost_LIBRARIES}
)

add_executable(puddles
	${SOURCES}
)

target_include_directories(puddles PUBLIC ${LIBS})
target_include_directories(puddles PUBLIC source/ )

target_link_libraries(puddles ${Boost_LIBRARIES})


enable_testing()

macro(add_test_h name)
	add_test(NAME test${name} COMMAND ${CMAKE_SOURCE_DIR}/tests/run.sh $<TARGET_FILE:puddles> ${CMAKE_SOURCE_DIR}/tests/vectors/${name}.in ${CMAKE_SOURCE_DIR}/tests/vectors/${name}.out)
	set_tests_properties(test${name} PROPERTIES TIMEOUT 5)
endmacro()


add_test_h(001)
add_test_h(002)
add_test_h(003)
add_test_h(004)
add_test_h(005)


cmake_minimum_required(VERSION 3.2)

project(puddles)

# find_package(Boost COMPONENTS filesystem program_options system regex thread REQUIRED)

list(APPEND CMAKE_CXX_FLAGS -std=c++11)

file(GLOB_RECURSE SOURCES "source/*")

set(LIBS
	# ${Boost_LIBRARIES}
)

add_executable(puddles
	${SOURCES}
)

target_include_directories(puddles PUBLIC submodules/spdlog/include)

target_link_libraries(puddles ${LIBS})

###################################################
############        TESTS        ##################
###################################################

enable_testing()

macro(add_test_h name)
	add_test(NAME test${name} COMMAND ${CMAKE_SOURCE_DIR}/tests/run.sh $<TARGET_FILE:puddles> ${CMAKE_SOURCE_DIR}/tests/vectors/${name}.in ${CMAKE_SOURCE_DIR}/tests/vectors/${name}.out)
	set_tests_properties(test${name} PROPERTIES TIMEOUT 5)
endmacro()

macro(add_test_i name)
	add_test(NAME test_i_${name} COMMAND ${CMAKE_SOURCE_DIR}/tests/neg.sh $<TARGET_FILE:puddles> ${CMAKE_SOURCE_DIR}/tests/vectors/i${name}.in)
	set_tests_properties(test${name} PROPERTIES TIMEOUT 5)
endmacro()

add_test_h(001)
add_test_h(002)
add_test_h(003)
add_test_h(004)
add_test_h(005)
add_test_h(006)
add_test_h(007)
add_test_h(008)

add_test_i(001)
add_test_i(002)
add_test_i(003)

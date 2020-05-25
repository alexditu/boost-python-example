cmake_minimum_required (VERSION 3.5)

# set (TOOLS /opt/toolchains/x86_64-pc-linux-gnu)
set (CMAKE_C_COMPILER   ${TOOLS}/usr/bin/gcc)
set (CMAKE_CXX_COMPILER ${TOOLS}/usr/bin/g++)

project (boost-python-example-project)

if (NOT ${INSTALL_DIR})
	message (STATUS "using default install dir: ${PROJECT_SOURCE_DIR}/installdir")
	set (INSTALL_DIR "${PROJECT_SOURCE_DIR}/installdir")
endif ()

set (CMAKE_VERBOSE_MAKEFILE ON)

set (BOOST_LIBS "/opt/boost/boost_1_73_0/builddir/lib")

include_directories ("${PROJECT_SOURCE_DIR}/include")
link_directories (
	"${PROJECT_SOURCE_DIR}/lib"
	"${BOOST_LIBS}"
)

set (SRCDIR "${PROJECT_SOURCE_DIR}/src")
file (GLOB PROJECT_SRCS "${PROJECT_SOURCE_DIR}/src/*.cpp")

set (ENV{BOOST_ROOT} "/opt/boost/boost_1_73_0")
find_package (Boost 1.66.0 REQUIRED)

message (STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
include_directories (${Boost_INCLUDE_DIRS})


add_subdirectory ("src/libtestlib")
add_subdirectory ("src/tests")



# main binary config (not used for the moment)
set (MAIN_BINARY "test-json")
add_executable (${MAIN_BINARY} "${PROJECT_SRCS}")


set_property(TARGET ${MAIN_BINARY} PROPERTY CXX_EXTENSIONS false)
set_property(TARGET ${MAIN_BINARY} PROPERTY CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")

target_link_libraries (${MAIN_BINARY} PRIVATE testlib pthread spdlog)

# set (RESOURCES_DIR "${PROJECT_SOURCE_DIR}/resources")
# configure_file ("${RESOURCES_DIR}/task.jso" "task.jso" COPYONLY)

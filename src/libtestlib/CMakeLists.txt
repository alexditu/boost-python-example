# set (CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
# set (CMAKE_INSTALL_RPATH "${BOOST_LIBS}")

# add link path to rpath
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_library (testlib SHARED testlib.cpp)

target_include_directories (testlib PUBLIC include PRIVATE "/usr/include/python2.7")

target_link_libraries (testlib PRIVATE spdlog boost_python27)

install (TARGETS testlib DESTINATION ${INSTALL_DIR})

cmake_minimum_required(VERSION 3.9)
project(RollerBufferExample)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS system filesystem unit_test_framework
        log log_setup thread REQUIRED)

include_directories ($(BOOST_ROOT))
include_directories ($(BOOST_LIBRARYDIR))
include_directories ($(BOOST_INCLUDEDIRS))

include_directories (src)

add_executable(RollerBufferExample main.cpp src/simpleLogger.cpp src/simpleLogger.h src/extendedRollingBuffer.cpp src/extendedRollingBuffer.h)

add_subdirectory(test)

if(Boost_FOUND)

    target_link_libraries(RollerBufferExample ${Boost_LIBRARIES})

endif()
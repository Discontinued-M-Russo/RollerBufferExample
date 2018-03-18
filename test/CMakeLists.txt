
add_executable (RollerBufferTest testRollingBuffer.cpp ../src/extendedRollingBuffer.cpp ../src/extendedRollingBuffer.h)

if(Boost_FOUND)

    target_link_libraries(RollerBufferTest ${Boost_LIBRARIES})

endif()
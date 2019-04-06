cmake_minimum_required (VERSION 3.8.1)

set(TEST_SRCS
    test.c
    )
    
set(VEC_TEST_SRCS
    ${TEST_SRCS}
    Vec_test.c
    )

include_directories(../src)

add_executable(Vec_test ${VEC_TEST_SRCS})
set_property(TARGET Vec_test PROPERTY C_STANDARD 99)
target_link_libraries(Vec_test Vec)

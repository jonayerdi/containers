cmake_minimum_required (VERSION 3.8.1)

set(TEST_SRCS
    test.c
    )
    
set(VECTOR_TEST_SRCS
    ${TEST_SRCS}
    vector_test.c
    )

include_directories(../src)

add_executable(vector_test ${VECTOR_TEST_SRCS})
set_property(TARGET vector_test PROPERTY C_STANDARD 99)
target_link_libraries(vector_test vector)

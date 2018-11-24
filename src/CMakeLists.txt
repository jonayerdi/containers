
set(VECTOR_SRCS
    vector.c
    )

add_library(vector ${VECTOR_SRCS})
set_property(TARGET vector PROPERTY C_STANDARD 99)

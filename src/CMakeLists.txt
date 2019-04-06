
set(VEC_SRCS
    Vec.c
    )

add_library(Vec ${VEC_SRCS})
set_property(TARGET Vec PROPERTY C_STANDARD 99)


set(VEC_SRCS
    Vec.c
    )

set(BST_SRCS
    BST.c
    )

add_library(Vec ${VEC_SRCS})
set_property(TARGET Vec PROPERTY C_STANDARD 99)

add_library(BST ${BST_SRCS})
set_property(TARGET BST PROPERTY C_STANDARD 99)

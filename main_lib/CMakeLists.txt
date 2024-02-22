project(main_lib)

set(HEADER_FILES
        library.h)

set(SOURCE_FILES
        library.cpp
        operations/add.cpp
        operations/subtraction.cpp
        operations/multiplication.cpp
        operations/division.cpp
)

add_library(main_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
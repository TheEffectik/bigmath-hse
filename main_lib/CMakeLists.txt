project(math)

set(HEADER_FILES
        library.h)

set(SOURCE_FILES
        library.cpp)

add_library(library STATIC ${SOURCE_FILES} ${HEADER_FILES})
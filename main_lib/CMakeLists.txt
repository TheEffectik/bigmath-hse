project(main_lib)

set(HEADER_FILES
        library.h)

set(SOURCE_FILES
        library.cpp)

add_library(main_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
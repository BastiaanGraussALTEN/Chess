# Set the source files for the main project
set(SRC_FILES
    main.cpp
    MoveDialog.cpp
    addition.cpp
    bar.cpp
)

# Set the header files for the main project
set(HEADER_FILES
    MoveDialog.h
    addition.h
    bar.h
)

# Add the executable or library
add_library(src STATIC ${SRC_FILES} ${HEADER_FILES})
include_directories(${CMAKE_SOURCE_DIR}/include)
set(SHAVED_SRCS
shaved.cpp
)

ADD_LIBRARY(shaved STATIC ${SHAVED_SRCS})

install_targets(/lib shaved)

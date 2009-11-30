set(SHAVED_SRCS
shaved.cpp shaved.hpp
)

ADD_LIBRARY(shaved STATIC ${SHAVED_SRCS})

install_targets(/lib shaved)

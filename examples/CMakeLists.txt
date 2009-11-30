include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(ex1 ex1.cpp)
target_link_libraries(ex1 shaved)
install_programs(/bin FILES ex1)

add_executable(test_matrix
    test_matrix.cpp
)

target_link_libraries(test_matrix PRIVATE tinytensor)

add_test(NAME matrix_smoke COMMAND test_matrix)

add_library(chess_bsp STATIC
    h723_board.cc
)

target_include_directories(chess_bsp PUBLIC
    .
    ../
)

target_link_libraries(chess_bsp
    PUBLIC
        driver
)
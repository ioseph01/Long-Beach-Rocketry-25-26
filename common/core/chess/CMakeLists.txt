add_library(chess STATIC
    chess_globals.cc chess_board.cc chess_manager.cc
)

target_include_directories(chess PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(chess PUBLIC
    container
)
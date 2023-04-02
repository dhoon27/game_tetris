#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "select.h"
#include "coordinate.h"

void init_screen()
{
    // int row = INIT_ROW;
    // int col = INIT_COL;
    // int row_size = INIT_ROW_SIZE;
    // int col_size = INIT_COL_SIZE;

    print_row_char(INIT_ROW, INIT_COL, INIT_ROW_SIZE + 1, "▩");
    print_row_char(INIT_ROW + INIT_COL_SIZE, INIT_COL, INIT_ROW_SIZE + 1, "▩");
    print_col_char(INIT_ROW + 1, INIT_COL, INIT_COL_SIZE - 1, "▩");
    print_col_char(INIT_ROW + 1, INIT_COL + INIT_ROW_SIZE, INIT_COL_SIZE - 1, "▩");

    strcpy(buf,"START");
    print_row_str((INIT_ROW + INIT_COL_SIZE/2), (INIT_COL + INIT_ROW_SIZE/2), sizeof(buf), buf);
    strcpy(buf,"EXIT");
    print_row_str((INIT_ROW + INIT_COL_SIZE/2)+INIT_ROW, (INIT_COL + INIT_ROW_SIZE/2), sizeof(buf), buf);

    print_row_char((INIT_ROW + INIT_COL_SIZE/2), (INIT_COL + INIT_ROW_SIZE/2)-3, 1, "★");

    select_game();
}

void game_screen()
{
    int row = 0;
    int col = 0;
    int row_size = 120;
    int col_size = 40;

    game_screen();
    
    print_row_char(row, col, row_size + 1, "▩");
    print_row_char(row + col_size, col, row_size + 1, "▩");
    print_col_char(row + 1, col, col_size - 1, "▩");
    print_col_char(row + 1, col + row_size, col_size - 1, "▩");
}
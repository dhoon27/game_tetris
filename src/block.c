#include <stdlib.h>
#include <unistd.h>

#include "coordinate.h"
#include "block.h"

int block_1[4][4][4] = {{{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                        {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                        {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                        {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
 
int block_2[4][4][4] = {{{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}},
                        {{1, 1, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                        {{1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
                        {{0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};

int block_3[4][4][4] = {{{0, 1, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}},
                        {{1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                        {{1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}},
                        {{1, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};

int block_4[4][4][4] = {{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                        {{0, 1, 0, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
                        {{0, 0, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
                        {{0, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}}};
                     
int block_5[4][4][4] = {{{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},
                        {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
                        {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},
                        {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}}};

int wall[GAME_COL_SIZE][GAME_ROW_SIZE];

// int* (block[5])[4][4] = {block_1, block_2, block_3, block_4, block_5};
static int block_num;
int (*block)[4][4];

void game_init()
{
    int i, j;
    for(i = 0; i < GAME_COL_SIZE; i++) {
        for(j = 0; j < GAME_ROW_SIZE; j++) {
            if(i == 0 || j == 0 || i == GAME_COL_SIZE -1 || i == GAME_ROW_SIZE - 1) {
                wall[i][j] = 1;
            }
        }
    }
}

void print_block(int y, int x, char* c)
{
    int i, j;
    switch (block_num)
    {
        case 1:
            block = block_1;
            break;
        case 2:
            block = block_2;
            break;
        case 3:
            block = block_3;
            break;
        case 4:
            block = block_4;
            break;
        case 5:
            block = block_5;
            break;
        default:
            break;
    }
    for (i = 0; i < MAX_BLOCK_SIZE; i++) {
            for (j = 0; j < MAX_BLOCK_SIZE; j++) {
                if (block[0][i][j] != 1) {
                    continue;
                }
                if (wall[y + i][x + j] == 1) {
                    continue;
                }
                print_row_char(y + i , x + j, 1, c);
            }
        }
}

void print_block_next()
{
    int py, px;
    py = NEXT_ROW + NEXT_COL_SIZE/2 - 1;
    px = NEXT_COL + NEXT_ROW_SIZE/2 - 1;
    

    block_num = (rand() % 5) + 1;
    print_block(py, px, "□");
    sleep(2);
    print_block(py, px, " ");   

}

void print_block_game()
{
    int py, px;
    py = GAME_ROW;
    px = GAME_ROW_SIZE/2;
    
    print_block(py, px, "□");
    sleep(1);
    print_block(py, px, " ");
}
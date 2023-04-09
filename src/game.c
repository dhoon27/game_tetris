#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "coordinate.h"
#include "keyboard.h"
#include "screen.h"
#include "game.h"
#include "block.h"

extern void game_init();
static int game_flag;

void game()
{
    game_flag = 1;
    game_init();
    game_screen();
    next_screen();

    while(game_flag) {
        print_block_next();
        print_block_game();
    }

    while(1);
}
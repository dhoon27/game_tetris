#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "select.h"
#include "coordinate.h"
#include "keyboard.h"
#include "game.h"

void select_game()
{
    int input;
    int select = 1;
    pid_t pid;

    while(1) {
        fflush(stdin);
        input = getch();
        if (input == 27) {
            input = getch();
            if (input == 91) {
                print_row_char((INIT_ROW + INIT_COL_SIZE/2), (INIT_COL + INIT_ROW_SIZE/2)-3, 1, " ");
                print_row_char((INIT_ROW + INIT_COL_SIZE/2)+1, (INIT_COL + INIT_ROW_SIZE/2)-3, 1, " ");
                input = getch();
                switch (input)
                {
                    case 65: // UP
                        print_row_char((INIT_ROW + INIT_COL_SIZE/2), (INIT_COL + INIT_ROW_SIZE/2)-3, 1, "★");
                        select = 1;
                        break;
                    case 68: // LEFT
                        /* code */
                        break;
                    case 67: // RIGHT
                        /* code */
                        break;
                    case 66: // DOWN
                        print_row_char((INIT_ROW + INIT_COL_SIZE/2)+1, (INIT_COL + INIT_ROW_SIZE/2)-3, 1, "★");
                        select = 0;
                        break;
                    default:
                        break;
                }
            }
        }
        else {
            if (input == 10) {
                system("clear");
                if(select) {
                    pid = fork();
                    if (pid == 0) {
                        game();
                    }
                    else if (pid > 0) {
                        wait(NULL);
                    }
                }
                else {
                    strcpy(buf,"EXIT");
                    print_row_str((INIT_ROW + INIT_COL_SIZE/2)+INIT_ROW, (INIT_COL + INIT_ROW_SIZE/2), sizeof(buf), buf);
                }
                return;
            }
        }
    }
}
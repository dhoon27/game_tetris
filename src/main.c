#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "keyboard.h"

void test()
{
    // int input;
    // while(1) {
    //     input = getch();
    //     if (input == 27) {
    //         input = getch();
    //         if (input == 91) {
    //             input = getch();
    //             switch (input)
    //             {
    //                 case 65: // UP
    //                     printf("input = %d\n", input);
    //                     break;
    //                 case 68: // LEFT
    //                     /* code */
    //                     break;
    //                 case 67: // RIGHT
    //                     /* code */
    //                     break;
    //                 case 66: // DOWN
    //                     printf("input = %d\n", input);
    //                     break;
    //                 default:
    //                     break;
    //             }
    //         }
    //     }
    //     printf("input = %d\n", input);
    // }
}

int main()
{
    unsigned long long time = 2100000000;
    
    system("clear");
    printf("\e[?25l");
    init_screen();

    while(time--);


    return 0;
}
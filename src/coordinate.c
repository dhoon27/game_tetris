#include <stdio.h>
#include <stdlib.h>
#include "coordinate.h"

void gotoxy(int y, int x)
{
    // \033 escape문자의 문법. 해당 y, x으로 cursor이동
    printf("\033[%d;%df",y, x); 
    // printf("hello");
    fflush(stdout); 
}

void print_row_char(int row, int col, int n, char* c)
{
    while(n--) {
        gotoxy(row, col++);
        printf("%s",c);
    }
    fflush(stdout);
}

void print_col_char(int row, int col, int n, char* c)
{
    while(n--) {
        gotoxy(row++, col);
        printf("%s",c);
    }
    fflush(stdout);
}

void print_row_str(int row, int col, int n, char* c)
{
    int i=0;
    while(n--) {
        gotoxy(row, col++);
        printf("%c",*(c+i));
        i++;
    }
    fflush(stdout);
}

void print_col_str(int row, int col, int n, char* c)
{
    int i=0;
    while(n--) {
        gotoxy(row++, col);
        printf("%c",*(c+i));
        i++;
    }
    fflush(stdout);
}
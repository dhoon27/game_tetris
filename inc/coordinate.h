#ifndef CCORDINATE__H
#define CCORDINATE__H

#define INIT_ROW         (0)
#define INIT_COL         (20)
#define INIT_ROW_SIZE    (40)
#define INIT_COL_SIZE    (20)

#define GAME_ROW         (0)
#define GAME_COL         (20)
#define GAME_ROW_SIZE    (20)
#define GAME_COL_SIZE    (20)

#define NEXT_ROW         (5)
#define NEXT_COL         (50)
#define NEXT_ROW_SIZE    (16)
#define NEXT_COL_SIZE    (8)

#define MAX_BUF_SIZE    (512)
char buf[MAX_BUF_SIZE];

/*
   stdout buf는 "\n",이 없거나 버퍼가 꽉 찬게 아니면 출력이 지연될 수 있음
   따라서 즉시 출력하도록 fflush 함수 사용, buffer는 clear됨 
*/
void gotoxy(int x, int y);
void print_row_char(int row, int col, int n, char* c);
void print_col_char(int row, int col, int n, char* c);
void print_row_str(int row, int col, int n, char* c);
void print_col_str(int row, int col, int n, char* c);
// 벽: ▩
// 움직 블럭: □
// 굳은 블럭: ■
// star : ★

#endif // CCORDINATE__H
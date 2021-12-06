#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int valid_move(int size, int board[size][size], int **eligible,int col, int row) {
    for (int i = 0; i < 8; i++) {
        if (eligible[i][0] == col && eligible[i][1] == row && board[eligible[i][1]][eligible[i][0]] == -1) {
            return 1;
        }
    }
    return 0;
}

int **valid_positions(int x, int y, int size) {
    int **eligible;
    eligible = malloc(sizeof(int*)*8);
    for (int i = 0; i < 8; i++) {
        eligible[i] = malloc(sizeof(int*)*2);
    }
    for (int i = 0; i < 8; ++i) {
        eligible[i][0]=-2;
        eligible[i][1]=-2;
    }
    int counter = 0;
    int moves[] = {-2,-1,1,2};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (x+moves[i]<size && x+moves[i]>=0 && y+moves[j]>=0 && y+moves[j]<size && (abs(moves[i])+abs(moves[j])==3)) {
                eligible[counter][0] = x+moves[i];
                eligible[counter][1] = y+moves[j];
                counter++;
            }
        }
    }
    return eligible;
}
int move_knight(int size, int board[size][size],int move,int row, int col) {
    int counter = 0;
    if (move == (size*size)) {
        //print_board(size,board);
        return 1;
    }
    int **eligible;
    eligible = valid_positions(col,row,size);
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (valid_move(size, board,eligible,x,y) == 1) {
                board[y][x] = move;
                int count = move_knight(size, board, move+1,y,x); 
                if (count != 0) {
                    counter += count;
                }
                board[y][x] = -1;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        free(eligible[i]);
    }
    free(eligible);
    return counter;
}

void print_board( int size, int board[size][size]) {
    printf("-------------------------\n");
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (col == 0) {
                printf("|");
            }
            if (board[row][col] == -1) {
                printf("    |");
            }
            else {
                printf("  %d |",board[row][col]);
            }
        }
        printf("\n-------------------------\n");
    }
}

int main(int argc, char *argv[] ) {
    if (argc < 2) return 1;
    // make board
    int total = 0;
    int board_size = atoi(argv[1]);
    int board[board_size][board_size];
    for (int row = 0; row < board_size; row++) {
        for (int col = 0; col < board_size; col++) {
            board[row][col] = -1;
        }
    }
    // prepare result board
    int result_board[board_size][board_size];
    for (int row = 0; row < board_size; row++) {
        for (int col = 0; col < board_size; col++) {
            result_board[row][col] = 0;
        }
    }
    // make all possible starts for n*n dimensional board
    for (int y = 0; y < board_size; y++) {
        for (int x = 0; x < board_size; x++) {
            board[y][x] = 0;
            int vysledek = move_knight(board_size,board,1,y,x);
            result_board[y][x] = vysledek;
            total += vysledek;
            board[y][x] = -1;
        }
    }
    printf("%d\n",total);
    print_board(board_size,result_board);

    return 0;
}
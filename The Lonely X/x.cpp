#include <iostream>
#include <conio.h>

int row = 10, col = 20;

int p_row = 0, p_col = 0;

void draw_board(){
    char board[row][col]{};
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j)
            board[i][j] = ' ';
    }
    board[p_row][p_col] = 'X';
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j)
            std::cout << board[i][j];
        std::cout << std::endl;
    }
}

int main() {
    draw_board();

    while(true){
        char choice = _getch();
        switch(choice){
            case 'a':{
                if (p_col - 1 >= 0){
                    p_col--;
                    system("cls");
                    draw_board();
                }
            }
            break;
            case 'd':{
                if (p_col + 1 < col){
                    p_col++;
                    system("cls");
                    draw_board();
                }
            }
            break;
            case 'w':{
                if (p_row - 1 >= 0){
                    p_row--;
                    system("cls");
                    draw_board();
                }
            }
            break;
            case 's':{
                if (p_row + 1 < row){
                    p_row++;
                    system("cls");
                    draw_board();
                }
            }
            break;
        }

    }   
}

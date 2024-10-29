#include <iostream>
#include <algorithm>

using namespace std;

char board[7000][7000];

void print_blank(int N, int start_row, int start_col){
    for(int i = start_row; i < start_row + N; i++){
            for(int j = start_col; j < start_col + N; j++){
                board[i][j] = ' '; 
            }
        }
}

void print_stars(int N, int start_row, int start_col){
    if(N == 3){

        for(int i = start_row; i < start_row + N; i++){
            for(int j = start_col; j < start_col + N; j++){
                if(i == start_row + 1 && j == start_col + 1){
                    board[i][j] = ' '; 
                }else{
                    board[i][j] = '*';
                }
            }
        }
    }else{

        int new_size = N / 3;

        for(int i = start_row; i < start_row + N; i += new_size){
            for(int j = start_col; j < start_col + N; j += new_size){

                if(i == start_row + new_size && j == start_col + new_size){
                    print_blank(new_size, i, j);
                }else

                    print_stars(new_size, i, j);

            }
        }

    }
}

int main(void){
    int N;
    
    cin >> N;

    print_stars(N, 0, 0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j];
        }
        cout << endl;

    }

    return 0;
}
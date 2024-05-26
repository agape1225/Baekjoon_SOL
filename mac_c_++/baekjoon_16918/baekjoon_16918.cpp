#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool check_range(int row, int col, int max_row, int max_col){
    if(row < 0 || row >= max_row || col < 0 || col >= max_col)
        return false;
    return true;
}

int main(void){
    int dir_x[4] = {0, 0, 1, -1};
    int dir_y[4] = {1, -1, 0, 0};

    string board[200];
    int cache[200][200];
    int R,C,N;
    int time = 0;

    cin >> R >> C >> N;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cache[i][j] = -1;
        }
    }

    for(int i = 0; i < R; i++){
        string tmp = "";
        cin >> tmp;

        for(int j = 0; j < C; j++){
            char c;
            c = tmp[j];
            if(c == 'O')
                cache[i][j] = time;
        }
        board[i] = tmp;
    }

    while(time < N){

        time++;

        if(time == 1)
            continue;
    
        //3초가 지난 폭탄 터트리기 (연쇄)
        if(time % 2){
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    if(time - cache[i][j] == 3){
                        board[i][j] = '.';
                        for(int k = 0; k < 4; k++){
                            int new_row = i + dir_x[k];
                            int new_col = j + dir_y[k];

                            if(check_range(new_row, new_col, R, C)){
                                board[new_row][new_col] = '.';
                            }
                        }
                    }
                }
            }
        }
        //빈칸에 폭탄 설치하기 (cache값 업데이트도 같이)
        else{
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    if(board[i][j] == '.'){
                        board[i][j] = 'O';
                        cache[i][j] = time;
                    }
                }
            }
        }

    }

    for(int i = 0; i < R; i++){
        cout << board[i] << endl;
    }
    
    return 0;
}
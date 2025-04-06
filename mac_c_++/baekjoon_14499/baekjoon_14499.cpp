#include <iostream>
#include <algorithm>

using namespace std;

bool check_range(int N, int M, int x, int y) {
    if(x < 0 || x >= N || y < 0 || y >= M){
        return false;
    }
    return true;
}

int get_next_dice(int dice, int commands) {

    int broute_force_table[6][4]  = {
        {3, 2,4,1},
        {3, 2,0,5},
        {0, 5,4,1},
        
        {5, 0,4,1},
        {3, 2,5,0},
        {3, 2,1,4},
    };

    return broute_force_table[dice][commands];

    int top_order[4] = {5, 4, 0, 1};
    int side_order[4] = {5, 2, 0, 3};
    int current_index = -1;

    if(commands == 0 ) {
        for(int i = 0; i < 4; i++) {
            if(side_order[i] == dice) {
                current_index = i;
                break;
            }
        }

        current_index = (current_index + 1) % 4;
        return side_order[current_index];
    }else if(commands == 1) {
        for(int i = 0; i < 4; i++) {
            if(side_order[i] == dice) {
                current_index = i;
                break;
            }
        }

        current_index--;
        if(current_index == -1) {
            current_index = 3;
        }
        return side_order[current_index];
    }else if(commands == 2) {
        for(int i = 0; i < 4; i++) {
            if(top_order[i] == dice) {
                current_index = i;
                break;
            }
        }
        current_index--;
        if(current_index == -1) {
            current_index = 3;
        }
        return top_order[current_index];
    }else {
        for(int i = 0; i < 4; i++) {
            if(top_order[i] == dice) {
                current_index = i;
                break;
            }
        }
        current_index = (current_index + 1) % 4;
        return top_order[current_index];
    }

}

int main(void) {

    int board[25][25] = {0};
    int commands[1005] = {0};

    int dice[6] = {0};
    int bottom_dice_num[6] = {5, 4, 3, 2, 1, 0};


    int dir_row[4] = {0, 0, -1, 1};
    int dir_col[4] = {1, -1, 0, 0};

    int N, M, x, y, K;
    int top_dice = 0;

    cin >> N >> M >> x >> y >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < K; i++) {
        cin >> commands[i];
    }

    for(int i = 0; i < K; i++) {

        int next_x = x + dir_row[commands[i] - 1];
        int next_y = y + dir_col[commands[i] - 1];

        if(!check_range(N, M, next_x, next_y)) {
            continue;
        }

        x = next_x;
        y = next_y;
        int new_dice[6] = {0};

        for(int j = 0; j < 6; j++) {
            new_dice[j] = dice[j];
        }


        if(commands[i] == 1) {
            new_dice[0] = dice[3];
            new_dice[3] = dice[5];
            new_dice[5] = dice[2];
            new_dice[2] = dice[0];

        }
        if(commands[i] == 2) {
            new_dice[0] = dice[2];
            new_dice[2] = dice[5];
            new_dice[5] = dice[3];
            new_dice[3] = dice[0];
            
        }
        if(commands[i] == 3) {
            new_dice[0] = dice[4];
            new_dice[4] = dice[5];
            new_dice[5] = dice[1];
            new_dice[1] = dice[0];
            
        }
        if(commands[i] == 4) {
            new_dice[0] = dice[1];
            new_dice[1] = dice[5];
            new_dice[5] = dice[4];
            new_dice[4] = dice[0];
        }

        for(int j = 0; j < 6; j++) {
            dice[j] = new_dice[j];
        }
        if(board[x][y] == 0) {
            //바닥면에 주사위가 복사
            
            board[x][y] = dice[5];        
        }else if(board[x][y] != 0) {
            //주사위에 바닥면이 복사
            dice[5] = board[x][y];
            board[x][y] = 0;

        }



        //top dice 조정
        // top_dice = get_next_dice(top_dice, commands[i] - 1);
        // int bottom_dice = bottom_dice_num[top_dice];

        // if(board[x][y] == 0) {
        //     //바닥면에 주사위가 복사
            
        //     board[x][y] = dice[bottom_dice];        
        // }else if(board[x][y] != 0) {
        //     //주사위에 바닥면이 복사
        //     dice[bottom_dice] = board[x][y];
        //     board[x][y] = 0;

        // }

        // cout << "----------------" << endl;
        // cout << top_dice << ' ' << bottom_dice << endl;
        // for(int row = 0; row < N; row++) {
        //     for(int col = 0; col < M; col++) {
        //         cout << board[row][col] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // for(int j = 0; j < 6; j++) {
        //     cout << dice[j] << ' ';
        // }
        // cout << endl << endl;

        // cout << ' ' << ' ' <<dice[1] << endl;
        // cout << dice[3] << ' ' << dice[0] << ' ' << dice[2] << endl;
        // cout << ' ' << ' ' <<dice[4] << endl;
        // cout << ' ' << ' ' <<dice[5] << endl;

        cout << dice[0] << '\n';

        // cout << "-----------------" << endl;
    }

    return 0;




}
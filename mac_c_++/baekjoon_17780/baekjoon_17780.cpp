#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int N, K;
int board[15][15];
vector<pair<int, int>> game_info[15][15];
int dir_row[5] = {0, 0, 0, -1, 1};
int dir_col[5] = {0, 1, -1, 0, 0};

pair<int,pair<int, int>> find_piece(int piece_num) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(game_info[i][j].size() > 0) {
                for(int order = 0; order < game_info[i][j].size(); order++) {
                    if(game_info[i][j][order].first == piece_num) {
                        return make_pair(
                            order,
                            make_pair(i, j)
                        );
                    }
                }
            }
        }
    }
}

bool is_game_end() {
    // return true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(game_info[i][j].size() >= 4) {
                return true;
            }
        }
    }
    return false;
}

pair<int, int> get_next_dir(pair<int,pair<int, int>> piece_pos_info) {
    int dir = game_info[piece_pos_info.second.first][piece_pos_info.second.second][piece_pos_info.first].second;
    return make_pair(
        piece_pos_info.second.first + dir_row[dir],
        piece_pos_info.second.second + dir_col[dir]
    );
}

int get_oppsited_dir(int dir){
    if(dir == 1) {
        return 2;
    }else if(dir == 2) {
        return 1;
    }else if(dir == 3) {
        return 4;
    }else if(dir == 4) {
        return 3;
    }
}
void set_next_dir(pair<int,pair<int, int>> piece_pos_info) {
    game_info[piece_pos_info.second.first][piece_pos_info.second.second][piece_pos_info.first].second = 
    get_oppsited_dir(game_info[piece_pos_info.second.first][piece_pos_info.second.second][piece_pos_info.first].second);
}

bool check_range(pair<int, int> next_dir) {
    if(next_dir.first < 0 || next_dir.first >= N || next_dir.second < 0 || next_dir.second >= N) {
        return false;
    }
    return true;
}

void move_piece() {
    for(int piece_num = 0; piece_num < K; piece_num++) {

        //움직여야하는 piece num

        //find piece
        pair<int,pair<int, int>> piece_pos_info = find_piece(piece_num);

        //가장 하단이 아니므로 패스
        if(piece_pos_info.first != 0) {
            continue;
        }

        pair<int, int> next_dir = get_next_dir(piece_pos_info);

        if(check_range(next_dir)) {

            if(board[next_dir.first][next_dir.second] == 0) {
                //white
                // 모든 객체를 옮기기
                int current_row = piece_pos_info.second.first;
                int currnet_col = piece_pos_info.second.second;

                for(int i = 0; i < game_info[current_row][currnet_col].size(); i++) {
                    game_info[next_dir.first][next_dir.second].push_back(game_info[current_row][currnet_col][i]);
                }

                while(game_info[current_row][currnet_col].size() > 0) {
                    game_info[current_row][currnet_col].pop_back();
                }

                // cout << "current: " << current_row << ' ' << currnet_col << endl;
                // cout << "next: " << next_dir.first << ' ' << next_dir.second << endl;
                // cout << "next size: " << game_info[next_dir.first][next_dir.second].size() << endl;
                // cout << "-----------------------------" << endl;

            }else if(board[next_dir.first][next_dir.second] == 1) {
                //red
                int current_row = piece_pos_info.second.first;
                int currnet_col = piece_pos_info.second.second;

                for(int i = game_info[current_row][currnet_col].size() - 1; i >= 0; i--) {
                    game_info[next_dir.first][next_dir.second].push_back(game_info[current_row][currnet_col][i]);
                }

                while(game_info[current_row][currnet_col].size() > 0) {
                    game_info[current_row][currnet_col].pop_back();
                }

                // reverse(game_info[next_dir.first][next_dir.second].begin(), game_info[next_dir.first][next_dir.second].end());


            }else if(board[next_dir.first][next_dir.second] == 2) {
                //blue
                int dir = game_info[piece_pos_info.second.first][piece_pos_info.second.second][piece_pos_info.first].second;
                int new_dir = get_oppsited_dir(dir);

            int next_row = piece_pos_info.second.first + dir_row[new_dir];
            int next_col = piece_pos_info.second.second + dir_col[new_dir];

            if(!check_range(make_pair(next_row, next_col)) || board[next_row][next_col] == 2) {
                //방향만 바꾸기
                game_info[piece_pos_info.second.first][piece_pos_info.second.second][piece_pos_info.first].second = new_dir;

            }else {
                //이동
                cout << piece_pos_info.second.first << ' ' << piece_pos_info.second.second  << ' ' << piece_pos_info.first  << ' ' << 
                game_info[piece_pos_info.second.first][piece_pos_info.second.second][piece_pos_info.first].second  << ' ' << new_dir << endl;
                game_info[piece_pos_info.second.first][piece_pos_info.second.second][piece_pos_info.first].second = new_dir;
                if(board[next_row][next_col] == 0) {
                    //white
                    // 모든 객체를 옮기기
                    int current_row = piece_pos_info.second.first;
                    int currnet_col = piece_pos_info.second.second;
    
                    for(int i = 0; i < game_info[current_row][currnet_col].size(); i++) {
                        game_info[next_row][next_col].push_back(game_info[current_row][currnet_col][i]);
                    }
    
                    while(game_info[current_row][currnet_col].size() > 0) {
                        game_info[current_row][currnet_col].pop_back();
                    }
                }else if(board[next_row][next_col] == 1) {
                    //red
                    int current_row = piece_pos_info.second.first;
                    int currnet_col = piece_pos_info.second.second;
    
                    for(int i = game_info[current_row][currnet_col].size() - 1; i >= 0; i--) {
                        game_info[next_row][next_col].push_back(game_info[current_row][currnet_col][i]);
                    }
    
                    while(game_info[current_row][currnet_col].size() > 0) {
                        game_info[current_row][currnet_col].pop_back();
                    }
    
                    // reverse(game_info[next_row][next_col].begin(), game_info[next_row][next_col].end());
    
    
                }

            }
                
            }

        }else {
            // 방향 변환하고 한 칸 가기
            // set_opposite_dir(piece_pos_info);
            int dir = game_info[piece_pos_info.second.first][piece_pos_info.second.second][piece_pos_info.first].second;
            int new_dir = get_oppsited_dir(dir);

            int next_row = piece_pos_info.second.first + dir_row[new_dir];
            int next_col = piece_pos_info.second.second + dir_col[new_dir];

            if(!check_range(make_pair(next_row, next_col)) || board[next_row][next_col] == 2) {
                //방향만 바꾸기
                game_info[piece_pos_info.second.first][piece_pos_info.second.second][piece_pos_info.first].second = new_dir;

            }else {
                //이동
                game_info[piece_pos_info.second.first][piece_pos_info.second.second][piece_pos_info.first].second = new_dir;
                if(board[next_row][next_col] == 0) {
                    //white
                    // 모든 객체를 옮기기
                    int current_row = piece_pos_info.second.first;
                    int currnet_col = piece_pos_info.second.second;
    
                    for(int i = 0; i < game_info[current_row][currnet_col].size(); i++) {
                        game_info[next_row][next_col].push_back(game_info[current_row][currnet_col][i]);
                    }
    
                    while(game_info[current_row][currnet_col].size() > 0) {
                        game_info[current_row][currnet_col].pop_back();
                    }
                }else if(board[next_row][next_col] == 1) {
                    //red
                    int current_row = piece_pos_info.second.first;
                    int currnet_col = piece_pos_info.second.second;
    
                    for(int i = game_info[current_row][currnet_col].size() - 1; i >= 0; i--) {
                        game_info[next_row][next_col].push_back(game_info[current_row][currnet_col][i]);
                    }
    
                    while(game_info[current_row][currnet_col].size() > 0) {
                        game_info[current_row][currnet_col].pop_back();
                    }
    
                    // reverse(game_info[next_row][next_col].begin(), game_info[next_row][next_col].end());
    
    
                }

            }


        }



    }
}

int main(void) {
    
    int ans = -1;

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++ ) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < K; i++) {
        int row, col, dir;
        cin >> row >> col >> dir;
        game_info[row - 1][col - 1].push_back(
            make_pair(i, dir)
        );
    }

    for(int i = 1; i <= 2; i++) {

        move_piece();

        for(int row = 0; row < N; row++) {
            for(int col = 0; col < N; col++) {
                if(game_info[row][col].size() > 0) {
                    cout << "current: " << row << ' ' << col << endl;
                    for(int j = 0; j < game_info[row][col].size(); j++) {
                        
                        cout << "( " << game_info[row][col][j].first + 1 << ' ' << game_info[row][col][j].second << " )" << endl;
                    }
                    cout << "----------------------------------------------" << endl;

                }
            }
        }


        if(is_game_end()) {
            ans = i;
            break;
        }

    }

    cout << ans;

    return 0;

}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//shark class

//d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.

class Shark {
    public:
    // int row, col;
    int speed;
    //방향
    int dir;
    //크기
    int size;

    Shark( int speed, int dir, int size) {
        // this->row = row;
        // this->col = col;Z
        this->speed = speed;
        this->dir = dir;
        this->size = size;
    }
};

class Ocean {
    public:
    // vector<Shark> shark_list;
    int fisher;
    int count_fish;
    int R, C;
    vector<Shark> board[105][105];

    Ocean (int R, int C){
        this->fisher = -1;
        this->count_fish = 0;
        this->R = R;
        this->C = C;
    }

    void catch_fish() {
        for(int row = 0; row < R; row++) {
            if(board[row][fisher].size() > 0) {
                count_fish += board[row][fisher][0].size;
                board[row][fisher].pop_back();
                // count_fish++;
                break;
            }
        }
    }

    pair<int, int> get_next_pos(int init_row, int init_col, Shark &shark) {
        //shark의 dir까지 수정해야한다.
        int speed_tmp = shark.speed;
        int row = init_row;
        int col = init_col;

        while(speed_tmp > 0) {
            if(shark.dir == 1) {
                //up
                int dis = row;

                if(dis <= speed_tmp) {
                    speed_tmp -= dis;
                    shark.dir = 2;
                    row = 0;
                }else {
                    row -= speed_tmp;
                    speed_tmp = 0;
                }
                // speed_tmp -= dis;

            }else if(shark.dir == 2) {
                //down
                int dis = this->R - row - 1;

                if(dis <= speed_tmp) {
                    speed_tmp -= dis;
                    shark.dir = 1;
                    row = this->R - 1;
                }else {
                    row += speed_tmp;
                    speed_tmp = 0;
                }

            }else if(shark.dir == 3) {
                //right
                int dis = this->C - col - 1;

                if(dis <= speed_tmp) {
                    speed_tmp -= dis;
                    shark.dir = 4;
                    col = this->C - 1;
                }else {
                    col += speed_tmp;
                    speed_tmp = 0;
                }

            }else if(shark.dir == 4) {
                //left
                int dis = col;

                if(dis <= speed_tmp) {
                    speed_tmp -= dis;
                    shark.dir = 3;
                    col = 0;
                }else {
                    col -= speed_tmp;
                    speed_tmp = 0;
                }

            }
        }

        
        return make_pair(row, col);

    }

    void move_fish() {
        // 일단 이동
        vector<Shark> new_board[105][105];

        for(int row = 0; row < R; row++) {
            for(int col = 0; col < C; col++) {
                if(board[row][col].size() > 0) {
                    Shark shark = board[row][col][0];

                    pair<int, int> next_pos = get_next_pos(row, col, shark);
                    new_board[next_pos.first][next_pos.second].push_back(shark);
                }
            }
        }
        // 같은 칸에 있는 애들 정리
        for(int row = 0; row < R; row++) {
            for(int col = 0; col < C; col++) {
                if(new_board[row][col].size() > 1) {
                    Shark shark = new_board[row][col][0];
                    for(int i = 1; i < new_board[row][col].size(); i++) {
                        if(shark.size < new_board[row][col][i].size) {
                            shark = new_board[row][col][i];
                        }
                    }
                    vector<Shark> new_vector;
                    new_vector.push_back(shark);
                    new_board[row][col] = new_vector;
                }
            }
        }

        //복사
        for(int row = 0; row < R; row++) {
            for(int col = 0; col < C; col++) {
                board[row][col] = new_board[row][col];
            }
        }
    }

    void print_board_info() {
        for(int row = 0; row < R; row++) {
            for(int col = 0; col < C; col++) {
                if(board[row][col].size() > 0) {
                    cout << "----------------" << endl;
                    cout << row << ' ' << col << endl;
                    for(auto it : board[row][col]) {
                        cout << it.size  << ' ' << it.dir << ' ' << it.speed << endl;
                    }
                }
            }
        }
    }

};

int main(void) {

    
    int R, C, M;
    int r,c,s,d,z;
    cin >> R >> C >> M;

    Ocean ocean(R, C);

    for(int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        // ocean.shark_list.push_back(Shark(r,c,s,d,z));
        ocean.board[r - 1][c - 1].push_back(Shark(s,d,z));
    }

    while(ocean.fisher < C) {
        //fisher move
        ocean.fisher++;

        //catch fish
        ocean.catch_fish();

        //move
        ocean.move_fish();
    }

    cout << ocean.count_fish << endl;

    
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int board[25][25] = {0};
int N;

int get_index(int r, int c, int x, int y, int d1, int d2){
    /*
    1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y, 1번 경계선의 왼쪽 위
    2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N, 2번 경계선의 오른쪽 위
    3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2, 3번 경계선의 왼쪽 아래
    4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N, 4번 경계선의 오른쪽 아래*/

    if(r < x + d1 && c <= y){
        return 1;
    }
    if(r <= x + d2 && y < c &&  c <= N){
        return 2;
    }
    if(x + d1 <= r && r <= N && c < y - d1 + d2){
        return 3;
    }
    if(x + d2 < r && r <= N && y - d1 + d2 <= c && c <= N)
        return 4;
    else 
        return 5;

    // cout << "damn! : " << r << ' ' << c << ' '<< x << ' '<< y << ' '<< d1 << ' '<< d2 << ' ' << endl;

    
}

int get_max_diff(int row, int col, int d1, int d2){
    int nums[6] = {0};
    int tmp[25][25] = {0};
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){

            int index = get_index(i, j, row, col, d1, d2);
            tmp[i][j] = index;
            nums[index] += board[i][j];
        }
    }

    int max_num = nums[1];
    int min_num = nums[1];

    for(int i = 2; i < 6; i++){
        max_num = max(nums[i], max_num);
        min_num = min(nums[i], min_num);
    }

    if(min_num == 0)
        return -1;
    else{
        cout << row << ' ' << col << ' ' << d1 << ' ' << d2 << ' ' << max_num - min_num << endl;
        for(int i = 1; i <= 5; i++){
            cout << nums[i] << ' ';
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                cout << tmp[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl << endl;
        return max_num - min_num;
    }

        
}

int main(void){
    int ans = -1;
    cin >> N;
    for(int row = 1; row <= N; row++){
        for(int col = 1; col <= N; col++){
            cin >> board[row][col];
        }
    }


    for(int row = 1; row <= N; row++){
        for(int col = 1; col <= N; col++){

            for(int d1 = 1; d1 <= N; d1++){
                for(int d2 = 1; d2 <= N; d2++){

                    //1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N

                    if(row < row + d1 + d2 && row + d1 + d2 <= N && 1 <= col - d1 &&
                    col - d1 < col && col < col + d2 && col + d2 <= N){
                        
                        int max_diff = get_max_diff(row, col, d1, d2);

                        if(max_diff == -1)
                            continue;

                        if(ans == -1){
                            ans = max_diff;
                        }else{
                            ans = min(ans, max_diff);
                        }

                    }

                }
            }
        }
    }

    cout << ans;

    return 0;

    
}
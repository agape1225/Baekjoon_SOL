#include <iostream>
#include <algorithm>

using namespace std;

int arr[1005][1005] = {0};

bool is_ans(int start_row, int start_col, int end_row, int end_col){
    for(int row = start_row; row < end_row; row++){
        for(int col = start_col; col < end_col; col++){
            if(arr[row][col] == 0){
                return false;
            }
        }
    }

    return true;
}

int main(void){
    
    int N, M;
    
    cin >> N >> M;

    while(N != 0 && M != 0){

        int ans = 0;
        int max = 0;

        for(int row = 0; row < N; row++){
            for(int col = 0; col < M; col++){
                cin >> arr[row][col];
            }
        }

        for(int start_row = 0; start_row < N; start_row++){
            for(int start_col = 0; start_col < M; start_col++){

                for(int end_row = start_row + 1; end_row <= N; end_row++){
                    for(int end_col = start_col + 1; end_col <= M; end_col++){

                        if(start_row == end_row || start_col == end_col){
                            continue;
                        }

                        if(is_ans(start_row, start_col, end_row, end_col)){
                            // cout << start_row << ' ' << start_col << ' ' << end_row << ' ' << end_col << endl;
                            int tmp = (end_row - start_row) * (end_col - start_col);
                            if(max < tmp){
                                ans = end_row - start_row;
                                max = tmp;
                            }
                        }

                    }
                }
                

            }
        }

        cout << ans << '\n';

        cin >> N >> M;

    }

    return 0;
}
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void get_ans(int start_row, int start_col, int N){
    
}


    int H, W, N;

    vector<int> r_list;
    vector<int> c_list;

bool is_poss(int num1, int num2){
    int x1 = r_list[num1];
    int y1 = c_list[num1];
    int x2 = r_list[num2];
    int y2 = c_list[num2];

    if(x1 + x2 <= H && y1 <= W &&  y2 <= W)
        return true;
    if(y1 + y2 <= W && x1 <= H &&  x2 <= H)
        return true;

    if(y1 + x2 <= H && x1 <= W &&  y2 <= W)
        return true;
    if(x1 + y2 <= W && y1 <= H &&  x2 <= H)
        return true;

    if(y1 + y2 <= H && x1 <= W &&  x2 <= W)
        return true;
    
    if(x1 + x2 <= W && y1 <= H &&  y2 <= H)
        return true;


    if(x1 + y2 <= H && y1 <= W &&  x2 <= W)
        return true;
    
    if(y1 + x2 <= W && x1 <= H &&  y2 <= H)
        return true;

    
    

    return false;
}

int main(void){

    int ans = 0;

    cin >> H >> W;
    cin >> N;

    for(int i = 0; i < N; i++){
        int r, c;

        cin >> r >> c;

        r_list.push_back(r);
        c_list.push_back(c);
    }

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            int num1 = i;
            int num2 = j;

            if(is_poss(num1, num2)){

                
                int tmp = r_list[num1] * c_list[num1];
                tmp += r_list[num2] * c_list[num2];

                cout << num1 << ' ' << num2 << ' ' << tmp << endl;

                ans = max(ans, tmp);
            }
        }
    }
    cout << ans;

    return 0;
}
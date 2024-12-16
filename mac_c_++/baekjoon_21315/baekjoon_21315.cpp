#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int ans[1005] = {0};
int arr[1005] = {0};
int N;

void shuffle(int K) {

    //카드 더미 중 밑에서 2K개의 카드를 더미의 맨 위로 올린다.
    stack<int> s;
    int index = N - 1 - pow(2, K);
    int prev_count = pow(2, K);
    while(index >= 0){
        s.push(arr[index--]);
    }

    index = N - 1;
    while(index > N - 1 - prev_count){
        s.push(arr[index--]);
    }

    for(int i = 0; i < N; i++){
        arr[i] = s.top();
        s.pop();

        // cout << arr[i] << ' ';
    }
    // cout << endl;

    //이후 i(2 ≤ i ≤ K + 1)번째 단계는 직전에 맨 위로 올린 카드 중 밑에서 2K - i + 1개의 카드를 더미의 맨 위로 올린다.
    
    for(int k = 2; k <= K + 1; k++){
        //prev count

        int end = prev_count;
        int begin = end - pow(2, K - k + 1);

        // cout << begin << ' ' << end << endl;

        for(int i = N - 1; i >= 0; i--){
            if(i < begin || i >= end){
                s.push(arr[i]);
            }
        }
        
        for(int i = end - 1; i >= begin; i--){
            s.push(arr[i]);
        }
        
        for(int i = 0; i < N; i++){
            arr[i] = s.top();
            s.pop();
        }

        prev_count = end - begin;
    }
}

bool is_match(){
    for(int i = 0; i < N; i++){
        if(ans[i] != arr[i]){
            return false;
        }
    }
    return true;
}

int main(void){

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> ans[i];
        arr[i] = i + 1;
    }

    for(int i = 1; pow(2, i) <= N; i++){
        for(int j = 1; pow(2, j) <= N; j++){

            shuffle(i);

            // for(int i = 0; i < N; i++){
            //     cout << arr[i] << ' ';
            // }
            // cout << endl;

            shuffle(j);

            // for(int i = 0; i < N; i++){
            //     cout << arr[i] << ' ';
            // }
            // cout << endl;

            if(is_match()){
                cout << i << ' ' << j;
                return 0;
            }

            // return 0;

            
            for(int k = 0; k < N; k++){
                arr[k] = k + 1;
            }  
        }
    }

    return 0;


}
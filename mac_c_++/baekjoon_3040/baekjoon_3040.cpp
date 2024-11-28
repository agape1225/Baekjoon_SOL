#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N = 9;
    int arr[9];
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    //for문 두개로 끝내장
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                continue;
            }

            int count = 0;
            for(int k = 0; k < N; k++){
                if(k != i && k != j){
                    count += arr[k];
                }
            }   

            if(count == 100){
                for(int k = 0; k < N; k++){
                    if(k != i && k != j){
                        cout << arr[k] << '\n';
                    }
                }

                return 0;
            }
        }
    }
}
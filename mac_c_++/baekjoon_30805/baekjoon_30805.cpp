#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int ans[105] = {0};
int ans_count = 0;

int get_max_index(int* comb, int index, int N){
    int max_index = index;
    int max_value = comb[index];

    for(int i = index + 1; i < N; i++){
        if(max_value < comb[i]){
            max_value = comb[i];
            max_index = i;
        }
    }

    return max_index;
}

void get_comb(int* arr1, int* arr2, int N, int M){

    int prev_index = 0;
    int index = 0;
    string comb = "";

    while(index < N){
        ind ex = get_max_index(arr1, index, N);

        int max_num = arr1[index];
        index++;
        
        for(int i = prev_index; i < M; i++){
            if(arr2[i] == max_num){
                // comb += to_string(max_num);
                ans[ans_count] = max_num;
                prev_index = i + 1;
                ans_count++;
                break;
            }
        }

    }
}

int main(void){
    int arr1[105];
    int arr2[105];
    int prev_index = 0;

    int N, M;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr1[i];
    }

    cin >> M;
    for(int j = 0; j < M; j++){
        cin >> arr2[j];
    }
    
    if(N < M){
        get_comb(arr1, arr2, N, M);
    }
    else{
        get_comb(arr2, arr1, M, N);
    }

    if(ans_count == 0){
        cout << 0;
    }else{
        cout << ans_count << endl;

        for(int i = 0; i < ans_count; i++ ){
            if(i == ans_count - 1){
                cout << ans[i];
            }else{
                cout << ans[i] << ' ';
            }
            
        }
    }

    
    return 0;

}

/*
3 1 4 1 5 9
1 1 1 1 1 2
5

23
7

3 2

*/
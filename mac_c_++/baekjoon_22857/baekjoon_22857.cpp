#include <iostream>

using namespace std;

int main(void){
    int N, K;
    int S[50005];
    int cache[50005];
    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    if(S[0] % 2)
        cache[0] = 0;
    else
        cache[0] = 1;

    for(int i = 1; i < N; i++){

        bool is_num_even = S[i] % 2 == 0;
        bool is_prev_even = S[i - 1] % 2 == 0;

        if(is_num_even){
            if(is_prev_even){
                cache[i] = cache[i - 1] + 1;
            }else{
                cache[i] = 1;
            }
        }else{
            if(is_prev_even){
                cache[i] = cache[i - 1];
            }else{
                cache[i] = 0;
            }
        }
    }

    for(int i = 0; i < N; i++)
        cout << S[i] << ' ';
    cout << endl;

    for(int i = 0; i < N; i++)
        cout << cache[i] << ' ';
    cout << endl; 

    return 0;


}
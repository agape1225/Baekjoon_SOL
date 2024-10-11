#include <iostream>

using namespace std;

int main(void){
    int hands[2] = {1, 2};
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){

        if(i == N - 1){


            if(i % 2 == 0){
                cout << 3;
            }else{
                cout << 2;
            }
        }else{
            cout << hands[i % 2] << ' ';
        }

        
    }

    return 0;
}
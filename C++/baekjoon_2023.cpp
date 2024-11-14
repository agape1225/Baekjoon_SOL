#include <iostream>
#include <algorithm>

using namespace std;

int N;

bool is_prime(int num){
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

void get_ans(int num, int count){
    if(count == N){
        cout << num << '\n';
    }else{
         for(int i = 1; i < 10; i++){
             int new_num = num * 10 + i;
             if(is_prime(new_num)){
                 get_ans(new_num, count + 1);
             }
         }   
    }
}

int main() {

    vector<int> prime = {2,3,5,7};
    cin >> N;

    for(auto it : prime){
        get_ans(it, 1);
    }
    
    return 0;
}

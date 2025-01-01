#include <iostream>
#include <algorithm>

using namespace std;

int arr[5] = {0};

bool is_num(int num) {
    int count = 0;

    for(int i = 0; i < 5; i++){
        if(num % arr[i] == 0){
            count++;
        }
    }

    return count > 2;
}

int main(void){
    
    int max_num = 0;
    int ans = -1;

    for(int i = 0; i < 5; i++){
        cin >> arr[i];
        max_num = max(max_num, arr[i]);
    }

    max_num = max_num * max_num * max_num;

    for(int i = 1; i <= max_num; i++){

        if(is_num(i)){
            ans = i;
            break;
        }

    }

    cout << ans;

    return 0;


}
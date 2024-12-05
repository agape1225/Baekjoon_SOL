#include <iostream>
#include <algorithm>

using namespace std;

int arr[15];
int is_erased[15] = {0};
int N;
int ans = 0;

int get_total(int index){
    int left = 0;
    int right = 0;
    int index_tmp = index;

    index_tmp--;
    while(true){
        if(!is_erased[index_tmp]){
            left = arr[index_tmp];
            break;
        }
        index_tmp--;
    }

    index_tmp = index;
    index_tmp++;
    while(true){
        if(!is_erased[index_tmp]){
            right = arr[index_tmp];
            break;
        }
        index_tmp++;
    }

    return left * right;
}

void get_ans(int total, int count){
    if(count == 2){
        ans = max(ans, total);
        return;
    }

    for(int i = 1; i < N - 1; i++){
        if(!is_erased[i]){
            is_erased[i] = true;
            get_ans(
                total + get_total(i), count - 1
            );
            is_erased[i] = false;
        }
    }


}

int main(void){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    get_ans(0, N);

    cout << ans;

    return 0;
}
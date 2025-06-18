#include <iostream>
#include <algorithm>

using namespace std;

int N;
int ans = 0;
int col[20] = {0};

bool check_queen(int index, int row) {
    for(int i = 1; i < index; i++) {
        // if(index == row) {
        //     continue;
        // }

        if(col[i] == row || (abs(col[i] - row) == abs(index - i))  ) {
            return false;
        }
    }
    return true;
}

void get_ans(int index) {

    if(index > N) {
        ans++;
        return;
    }

    for(int i = 1; i <= N; i++) {
        if(check_queen(index, i)) {
            col[index] = i;
            get_ans(index + 1);
        }
    }



}

int main(void) {
    cin >> N;
    
    get_ans(1);

    cout << ans;

    return 0;

}
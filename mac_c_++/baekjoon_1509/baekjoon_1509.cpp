#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int N;
string str;
bool is_palindrome[2505][2505] = {0};
int dp[2505] = {0};

int main(void) {

    cin >> str;
    N = str.size();

    //set is palindrome

    //size one
    for(int i = 0; i < N; i++) {
        is_palindrome[i][i] = true;
    }

    //size two
    for(int i = 0; i < N -1; i++) {
        if(str[i] == str[i + 1]) {
            is_palindrome[i][i + 1] = true;
        }
    }

    for(int len = 0; len <= N; len++) {
        for(int i = 0; i < N; i++) {
            int end = i + len - 1;
            if(end < N) {
                if(str[i] == str[end]) {
                    if(is_palindrome[i + 1][end - 1]) {
                        is_palindrome[i][end] = true;
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 2; j < N; j++) {
            if(str[i] == str[j]) {
                if(is_palindrome[i + 1][j - 1]) {
                    is_palindrome[i][j] = true;
                }
            }
        }
    }

    //dp 시작하기
    for(int end = 1; end <= N; end++) {
        dp[end] = 987654321;
        for(int start = 1; start <= end; start++) {
            if(is_palindrome[start - 1][end - 1]) {
                dp[end] = min(dp[end], dp[start - 1] + 1);
            }
        }
    }

    cout << dp[N];

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         cout << is_palindrome[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;

}
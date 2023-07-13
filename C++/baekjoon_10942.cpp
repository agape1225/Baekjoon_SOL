#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)
#define NMAX 2000 + 1 
int main() {
    int N, M; int num[NMAX] = { 0 }; int is_palindrome[NMAX][NMAX] = { 0 };
    scanf("%d", &N);
    for (int n_idx = 1; n_idx <= N; n_idx++)
        scanf("%d", &num[n_idx]);
    // 초기화
    int gap = 0;
    for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
        int end_idx = start_idx + gap;
        is_palindrome[start_idx][end_idx] = 1;
    }
    gap = 1;
    for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
        int end_idx = start_idx + gap;
        if (num[start_idx] == num[end_idx])
            is_palindrome[start_idx][end_idx] = 1;
    }
    // 팰린드롬은 양 끝이 달라지는 것이기 때문에
    // start_idx 와 end_idx를 각각 +1,-1을 한 것이 팰린드롬이고, 양끝이 같으면 == 팰린드롬 
    // start_idx 와 end_idx를 각각 +1,-1을 한 것이 팰린드롬이 아니거나, 양끝이 다르면 != 팰린드롬
    for (gap = 2; gap <= N; gap++) {
        for (int start_idx = 1; start_idx + gap <= N; start_idx++) {
            int end_idx = start_idx + gap;
            if (is_palindrome[start_idx + 1][end_idx - 1] && num[start_idx] == num[end_idx])
                is_palindrome[start_idx][end_idx] = 1;
        }
    }
    scanf("%d", &M);
    while (M--) {
        int start, end; scanf("%d %d", &start, &end);
        printf("%d\n", is_palindrome[start][end]);
    }
    return 0;
}
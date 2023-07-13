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
    // �ʱ�ȭ
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
    // �Ӹ������ �� ���� �޶����� ���̱� ������
    // start_idx �� end_idx�� ���� +1,-1�� �� ���� �Ӹ�����̰�, �糡�� ������ == �Ӹ���� 
    // start_idx �� end_idx�� ���� +1,-1�� �� ���� �Ӹ������ �ƴϰų�, �糡�� �ٸ��� != �Ӹ����
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
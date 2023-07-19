#include <iostream>
#include <cstring> //memset

using namespace std;
const int MAX = 100000 + 1;

int N, cnt;
int want[MAX];
bool visited[MAX];
bool done[MAX]; //�湮�� �������� ����

void DFS(int nodeNum){

    visited[nodeNum] = true;
    int next = want[nodeNum];

    if (!visited[next])
        DFS(next);

    else if (!done[next]) {
        for (int i = next; i != nodeNum; i = want[i])
            cnt++;
        cnt++;
    }
    done[nodeNum] = true;
}



int main(void) {

    int T;
    cin >> T;

    for (int i = 0; i < T; i++){

        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
        
        cin >> N;

        for (int j = 1; j <= N; j++)

            cin >> want[j];

        cnt = 0;

        for (int j = 1; j <= N; j++)
            if (!visited[j])
                DFS(j); //���� �̷�� ������� ����

        cout << N - cnt << endl;
    }

    return 0;
}
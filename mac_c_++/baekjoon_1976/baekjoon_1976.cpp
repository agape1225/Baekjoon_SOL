#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main(void){
    int N, M;
    bool graph[205][205];
    int ans[1005];
    bool cache[205][205] = {0};
    
    cin >> N >> M;

    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        cin >> ans[i];
    }

    //일단 cache를 생성한다. (가기만 하면 되는 곳을 표시)
    for(int i = 0; i < N; i++){

        cache[i][i] = true;

        //bfs 진행
        queue<int> q;
        bool visited[205] = {0};

        q.push(i);
        visited[i] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int j = 0; j < N; j++){
                if(graph[node][j] && !visited[j]){
                    cache[i][j] = true;
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << cache[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    //ans 판단
    string str = "YES";

    for(int i = 0; i < M - 1; i++){
        int from = ans[i] - 1;
        int to = ans[i + 1] - 1;

        if(!cache[from][to]){
            str = "NO";
            break;
        }
    }

    cout << str;

    return 0;


}
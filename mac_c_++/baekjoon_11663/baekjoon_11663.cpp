#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int N, M, point, start, end;
    vector<int> points;
    vector<pair<int, int>> lines;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> point;
    }

    for(int i = 0; i < M; i++){
        cin >> start >> end;
        lines.push_back(make_pair(start, end));
    }

    
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

bool comp(pair<int,int> n1, pair<int, int>n2){
    if(n1.first == n2.first){
        return n1.second < n2.second;
    }
    return n1.first < n2.first;
}

    int n, T;
    vector<pair<int, int>> locations;
    queue<pair<int, pair<int, int>>> q;
    // bool visited[1000005][200005] = {0};
    bool visited[50005] = {0};

int main(void){

    int ans = -1;
    bool is_poss = false;

    cin >> n >> T;

    for(int i = 0; i < n; i++){
        int tmp_x, tmp_y;
        cin >> tmp_x >> tmp_y;

        if(T == tmp_y){
            is_poss = true;
        }

        locations.push_back(make_pair(tmp_x, tmp_y));
    }

    if(!is_poss){
        cout << ans;
        return 0;
    }

    sort(locations.begin(), locations.end(), comp);

    q.push(make_pair(0, make_pair(0, 0)));

    while(!q.empty()){
        int current_x = q.front().second.first;
        int current_y = q.front().second.second;
        int current_count = q.front().first;
        q.pop();

        if(current_y == T){
            ans = current_count;
            break;
        }

        //다음 노드에 이분탐색
        for(int row = current_x - 2; row <= current_x + 2; row++){
            for(int col = current_y - 2; col <= current_y + 2; col++){
                if(row < 0 || col < 0)
                    continue;
                pair<int, int> next_locations = make_pair(row, col);
                auto it = lower_bound(locations.begin(), locations.end(), next_locations);

                if(it != locations.end() && *it == next_locations){
                    int index = it - locations.begin();
                    if(!visited[index]){
                        visited[index] = true;
                        q.push(make_pair(current_count + 1, make_pair(next_locations.first, next_locations.second)));
                    }

                }
            }
        }

    }

    cout << ans;

    return 0;

}
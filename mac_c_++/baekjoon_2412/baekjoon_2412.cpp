#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

bool comp(pair<int,int> n1, pair<int, int>n2){
    if(n1.second == n2.second){
        return n1.first < n2.first;
    }
    return n1.second < n2.second;
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

    // sort(locations.begin(), locations.end(), comp);

    //for(auto it: locations){
      //  cout << it.first << ' ' << it.second << endl;
    //}

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

        for(int i = 0; i < n; i++){
            int target_x = locations[i].first;
            int target_y = locations[i].second;

            if(!visited[i]){

                if(abs(target_y - current_y) > 2){
                    break;
                }

                if( abs(target_x - current_x) <= 2){
                    visited[i] = true;
                    q.push(make_pair(current_count + 1, make_pair(target_x, target_y)));
                }
                
            }
        }
        for(int i = n - 1; i >= 0; i--){
            int target_x = locations[i].first;
            int target_y = locations[i].second;

            if(!visited[i]){

                if(abs(target_x - current_x) > 2){
                    break;
                }
                if( abs(target_y - current_y) <= 2){
                    visited[i] = true;
                    q.push(make_pair(current_count + 1, make_pair(target_x, target_y)));
                }
                
            }
        }

    }

    cout << ans;

    return 0;

}
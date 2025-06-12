#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <queue>

using namespace std;

// cost[i][j] = i와 j번째를 교환할 때 드는 비용
int cost[15][15] = {0};
// int arr[10] = {0};
string arr;
// set<string> s;
map<string, long long> m;
priority_queue<pair<long long, string>> q;
int N, M;
int l, r, c;
long long ans = -1;
char tmp;

int main(void) {

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        arr += tmp;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cost[i][j] = -1;
        }
    }


    cin >> M;

    for(int i = 0; i < M; i++) {
        cin >> l >> r >> c;
        cost[l - 1][r - 1] = c;
    }

    q.push(make_pair(0, arr));
    // s.insert(arr);

    m.insert(make_pair(arr, 0));

    sort(arr.begin(), arr.end());

    while(!q.empty()) {
        string current_str = q.top().second;
        long long current_count = -q.top().first;
        q.pop();

        if(current_count > m.find(current_str)->second) {
            continue;
        }

        // s.insert(current_str);
        if(arr == current_str) {
            if(ans == -1) {
                ans = current_count;
            }else {
                ans = min(ans, current_count) ;
            }
            
            // continue;
            break;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                // cost[i][j] = -1;
                if(cost[i][j] != -1) {
                    string tmp_str = current_str;
                    char tmp_char = tmp_str[i];
                    tmp_str[i] = tmp_str[j];
                    tmp_str[j] = tmp_char;

                    auto it = m.find(tmp_str);


                    if(it == m.end()) {
                        m.insert(make_pair(tmp_str, (current_count + cost[i][j])));
                        q.push(make_pair(-(current_count + cost[i][j]), tmp_str));
                    }else{
                        if(it->second > current_count + cost[i][j]) {
                            it->second =current_count + cost[i][j];
                            q.push(make_pair(-(current_count + cost[i][j]), tmp_str));
                        }
                    }

                    // if(s.find(tmp_str) == s.end()) {
                        
                        
                    // }

                    
                }
            }
        }
    }

    cout << ans;
    return 0;

}
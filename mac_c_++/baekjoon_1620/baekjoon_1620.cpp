#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // set<string> s;
    map<string, int> pocketmon_dic;
    vector<string> pocketmon_arr;
    
    int N, M;
    string tmp;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        // s.insert(tmp);
        pocketmon_arr.push_back(tmp);
        pocketmon_dic.insert(make_pair(tmp, i + 1));
    }

    for(int i = 0; i < M; i++) {
        cin >> tmp;

        if('A' <= tmp[0] && tmp[0] <= 'Z') {
            cout << pocketmon_dic.find(tmp)->second << '\n';
        }else {
            cout << pocketmon_arr[stoi(tmp) - 1] << '\n';
        }

        // if("1" <= tmp && tmp <= to_string(N)) {
        //     cout << stoi(tmp) - 1;
        //     // auto it  = s.begin();
        //     // it += stoi(tmp);
        //     // cout << *it << '\n';
        //     cout << pocketmon_arr[stoi(tmp) - 1] << '\n';
        // }else {
        //     // int index = s.find(tmp);
        //     // cout << (s.find(tmp)) - (s.begin()) << '\n';
        //     cout << pocketmon_dic.find(tmp)->second << '\n';
        // }
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool comp(pair<int, int> node1, pair<int, int> node2){
    if(node1.second == node2.second){
        return node1.first < node2.first;
    }
    return node1.second < node2.second;
}

int main(void){
    int n;
    vector<pair<int, int>> tree_info;
    long long ans = 0;

    int length[100005] = {0};
    int growth[100005] = {0};

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> length[i];
    }

    for(int i = 0; i < n; i++){
        cin >> growth[i];

        tree_info.push_back(
            make_pair(length[i], growth[i])
        );
    };

    sort(tree_info.begin(), tree_info.end(), comp);

    for(int i = 0; i < n; i++){
        ans += tree_info[i].first + (i * tree_info[i].second);
    }

    cout << ans;

    return 0;

}
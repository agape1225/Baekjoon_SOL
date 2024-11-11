#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool cmp(pair<int, int> n1, pair<int, int> n2){
    if(n1.second == n2.second){
        return n1.first < n2.first;
    }else{
        return n1.second < n2.second;
    }
}

int main(void){
    int tree[100005];
    int weight[100005];
    long long ans = 0;
    vector<pair<int, int>> trees;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> tree[i];
    }

    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }

    for(int i = 0; i < n; i++){
        trees.push_back(make_pair(tree[i], weight[i]));
    }

    sort(trees.begin(), trees.end(), cmp);

    for(int i = 0; i < n; i++){
        ans += trees[i].first + (i * trees[i].second);
    }

    cout << ans;

    return 0;

}
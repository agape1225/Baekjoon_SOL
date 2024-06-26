#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N, M, tree, max_tree;
    vector<int> trees;
    int left, right, mid ,ans;

    max_tree = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> tree;
        trees.push_back(tree);
        max_tree = max(max_tree, tree);
    }

    left = 0;
    right = max_tree;
    ans = 0;

    sort(trees.begin(), trees.end());

    while(left <= right){
        mid = (left + right) / 2;
        long long tmp = 0;
        for(auto it : trees){
            if(mid < it){
                tmp += it - mid;
            }
        }

        // cout << mid << ' ' << tmp << endl;

        if(tmp >= M){
            left = mid + 1;
            ans = mid;
        }else{
            right = mid - 1;
        }

    }
    cout << ans;

    return 0;


}
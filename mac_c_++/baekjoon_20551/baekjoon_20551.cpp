#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, tmp;
    vector<int> arr;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < M; i++){
        cin >> tmp;
        // cout << binary_search(arr.begin(), arr.end(), tmp) << '\n';
        auto it = lower_bound(arr.begin(), arr.end(), tmp);
        // cout << *it;
        if(it == arr.end() || tmp != (*it)){
            cout << -1 << '\n';
        }else{
            cout << it - arr.begin() << '\n';
        }

    }

    return 0;

    
}
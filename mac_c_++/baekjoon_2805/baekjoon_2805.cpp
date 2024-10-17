#include <iostream>
#include <algorithm>

using namespace std;

int trees[1000005];

int main(void){

    //이분 탐색 이지렁!

    int N, M;
    
    int left = 1;
    int right = 1;
    int ans = -1;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> trees[i];
        right = max(right, trees[i]);
    }

    // ans = right;

    while(left <= right){
        int mid = (left + right) / 2;
        int tree_sum = 0;

        for(int i = 0; i < N; i++){
            if(trees[i] > mid){
                tree_sum += trees[i] - mid;
            }
        }

        if(tree_sum < M){
            right = mid - 1;
            
        }else{
            left = mid + 1;
            ans = mid;
        }
    }

    cout << ans;

    return 0;

}
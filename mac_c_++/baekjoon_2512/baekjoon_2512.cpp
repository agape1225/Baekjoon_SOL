#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> budget;

int get_sum(int mid){
    int sum = 0;
    for(auto it : budget){
        if(mid >= it){
            sum += it;
        }else
            sum += mid;
    }
    return sum;
}
int main(void){
    int N, M, tmp;
    int total_sum = 0;
    int max_num = 0;
    int ans = 0;
    int ans_index = -1;

    cin >> N;

    for(int i = 0; i < N; i++){
        //int tmp;
        cin >> tmp;
        total_sum += tmp;
        max_num = max(max_num, tmp);
        budget.push_back(tmp);
    }

    cin >> M;

    if(total_sum <= M){
        cout << max_num;
        return 0;
    }
    
    int left = 0;
    int right = M;
    int mid = -1;

    while(left < right - 1){
        //stop condition

        // cout << left << ' ' << right << ' ' << mid << endl;
        
        mid = (left + right) / 2;
        int sum = get_sum(mid);
        if(sum >= M){
            right = mid;
        }else{
            left = mid;
        }
    }

    cout << mid;


}
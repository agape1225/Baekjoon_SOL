#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main(void) {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N, K;
    int count_num[100005] = {0};
    int arr[200005] = {0};
    int answer = 0;
    map<int, int> m;
    set<int> s;

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];  
        // count_num[arr[i]]++;
    }

    answer = 1;
    count_num[arr[0]] ++;

    int left = 0;
    int right = 1;

    while(right < N) {
        count_num[arr[right]]++;
        if(count_num[arr[right]] <= K) {
            answer = max(answer, right - left + 1);
        }else {
            //left 조정 하기
        }
    }


    return 0;


}
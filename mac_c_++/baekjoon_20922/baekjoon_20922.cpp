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
    map<int, int> m;
    set<int> s;

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        count_num[arr[i]]++;
    }

    for(int i = 1; i < 100005; i++) {
        if(count_num[i] > K) {
            // m.insert(make_pair(i, count_num[i]));
            s.insert(i);
        }
    }

    int left = 0;
    int right = N - 1;

    //갸장 가까운 애를 찾는건가...?

    while(left <= right && s.size() > 0) {

        if(s.find(arr[left]) != s.end()) {
            count_num[left]--;
            if(count_num[left] <= K) {
                s.erase(arr[left]);
            }
            left++;
        }else if(s.find(arr[right]) != s.end()) {
            //여기가 제일 중요
            count_num[right]--;
            if(count_num[right] <= K) {
                s.erase(arr[right]);
            }
            right--;

        }else {

            int new_left = left + 1;
            int new_right = right - 1;
            bool is_left_changed = false;
            bool is_right_changed = false;
            
            while(new_left <= new_right) {
                if(s.find(arr[new_left]) != s.end() ) {
                    count_num[new_left]--;
                    if(count_num[new_left] <= K) {
                        s.erase(arr[new_left]);
                    }
                    new_left++;
                    is_left_changed = true;
                    break;
                }else if( s.find(arr[new_right]) != s.end()) {
                    count_num[new_right]--;
                    if(count_num[new_right] <= K) {
                        s.erase(arr[new_right]);
                    }
                    new_right--;
                    is_right_changed = true;
                    break;
                }else {
                    new_left++;
                    new_right--;
                }
            }

            if(is_left_changed) {
                left = new_left;
            }else if(is_right_changed) {
                right = new_right;
            }
        }

    }

    cout << right - left + 1;


    return 0;


}
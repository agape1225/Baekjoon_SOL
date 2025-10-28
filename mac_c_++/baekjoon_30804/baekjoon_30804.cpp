#include <iostream>
#include <algorithm>
#define ANSWER_COUNT 2
using namespace std;

int main(void) {
    int N, tmp;
    int answer = 0;

    cin >> N;
    
    vector<int> tangtang(N + 1);
    vector<int> count_fruit(N + 1, 0);
    int count_total_fruit = 0;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        tangtang[i] = tmp;

        // if(count_fruit[tmp] == 0) {
        //     count_total_fruit++;
        // }
        // count_fruit[tmp]++;
    }

    // for(auto it : tangtang) {
    //     cout << it << ' ';
    // }
    // cout << endl;

    int start = 0;
    int end = 1;
    count_total_fruit++;
    count_fruit[tangtang[start]]++;
    answer = 1;

    while(start < end && end < N) {

        while(end < N && count_total_fruit <= ANSWER_COUNT) {
            int fruit = tangtang[end];
            // cout << fruit << ' ' << count_fruit[fruit] << endl;
            if(count_fruit[fruit] == 0) {
                count_total_fruit++;
            }
            end++;
            count_fruit[fruit]++;

            if(count_total_fruit <= ANSWER_COUNT) {
                // cout << "end++" << endl;
                // cout << count_total_fruit << ' ' << ANSWER_COUNT << endl;
                // cout << start << ' ' << end << endl;
                answer = max(answer, end - start);
            }
        }

        while(start < N && count_total_fruit > ANSWER_COUNT) {
            // cout << "start++" << endl;
            int fruit = tangtang[start];
            if(--count_fruit[fruit] == 0) {
                count_total_fruit--;
            }
            start++;
        }
    }

    cout << answer;

    return 0;
    
}
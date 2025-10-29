#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M, tmp;
    vector<int> answer;
    vector<int> a;
    vector<int> b;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        b.push_back(tmp);
    }

    int index_a = 0;
    int index_b = 0;

    while (index_a < N && index_b < M )
    {
        int max_a_index = -1;
        int max_a_num = -1;
        int max_b_index = -1;
        int b_arr_count[105] = {0};

        for(int i = index_b; i < M; i++) {
            b_arr_count[b[i]]++;
        }

        for(int i = index_a; i < N; i++) {
            if(a[i] > max_a_num && b_arr_count[a[i]] > 0) {
                max_a_num = a[i];
                max_a_index = i;
            }
        }

        if(max_a_index == -1) {
            break;
        }

        for(int i = index_b; i < M; i++) {
            if(b[i] == max_a_num) {
                index_b = i + 1;
                break;
            }
        }

        answer.push_back(max_a_num);
        index_a = max_a_index + 1;
    }
    
    cout << answer.size() << '\n';
    for(auto it : answer) {
        cout << it << ' ';
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

// bool cmp(pair<int, pair<int, int>> node1, pair<int, pair<int, int>> node2) {
//     if(node1.first == node2.first){
//         return node1.second.first < node2.second.first;
//     }else {
//         return node1.first < node2.first;
//     }
// }

struct cmp{
bool operator() (pair<int, pair<int, int>> &node1, pair<int, pair<int, int>> &node2) {
    if(node1.first == node2.first){
        return node1.second.first > node2.second.first;
    }else {
        return node1.first > node2.first;
    }
}
};

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>> ,cmp> pq;

void print_pq() {
    if(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        print_pq();
        cout << it.second.second << ' ';
    }
}

int main(void) {
    

    int N, recomend_count, tmp;
    cin >> N >> recomend_count;

    for(int i = 0; i < recomend_count; i++){

        cin >> tmp;

        // auto it:
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>> ,cmp> new_pq;
        bool is_find = false;

        while(!pq.empty()) {
            if(pq.top().second.second == tmp) {
                // pq.top().first = pq.top().first + 1;
                is_find = true;
                new_pq.push({pq.top().first + 1,  {pq.top().second.first, pq.top().second.second}  });
            }else{
                 new_pq.push(pq.top());
            }
            pq.pop();
           
        }

        pq = new_pq;

        if(!is_find){
            if(pq.size() == N) {
                pq.pop();
            }
            pq.push({1, {i, tmp}});
        }
    }


    // while(!pq.empty()) {
    //     cout << pq.top().first << ' ' << pq.top().second.first << ' ' << pq.top().second.second << endl;
    //     pq.pop();
    // }

    // print_pq();

    // pq.push({5, {3, 4} });
    // pq.push({5, {2, 4} });

    // cout << pq..first;
    vector<int> ans;

    while(!pq.empty()) {
        // cout << pq.top().first << ' ' << pq.top().second.first << ' ' << pq.top().second.second << endl;
        ans.push_back(pq.top().second.second);
        pq.pop();

        
    }

    sort(ans.begin(), ans.end());

    for(auto it : ans) {
        cout << it << ' ';
    }


    return 0;



}
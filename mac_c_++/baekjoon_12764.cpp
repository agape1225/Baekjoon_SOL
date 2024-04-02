#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main(void){
    int N;
    priority_queue<pair<int, int>> pq;
    multimap<int, int> input;
    set<int> save;
    int ans[1000000] = {0};

    int ans_index = 0;
    int start, end;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> start >> end;
        input.insert(make_pair(start, end));
    }

    for(auto it : input){

        while(!pq.empty()){
            if(-pq.top().first <= it.first){
                save.insert(pq.top().second);
                pq.pop();
            }else
                break;
        }

        //empty seat
        if(save.empty()){
            pq.push(make_pair(-it.second, ans_index));
            ans[ans_index]++;
            ans_index++;
        }else{
            int tmp = *save.begin();
            pq.push(make_pair(-it.second, tmp));
            ans[tmp]++;
            save.erase(save.begin());

        }

    }
    cout << ans_index << endl;
    for(int i = 0; i < ans_index; i++){
        cout << ans[i] << ' ';
    }


    return 0;
}
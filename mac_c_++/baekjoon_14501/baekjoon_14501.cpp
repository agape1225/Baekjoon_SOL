#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> times;
vector<int> pays;
bool visited[15] = {0};
int index_list[15] = {0};
int ans = 0;
int N;

void get_max(int index){
    if(index >= N){

        int prev_index = -1;
        int count = 0;

        for(int i = 0; i < N; i++){
            if(index_list[i]){
                if(prev_index == -1 && i + 1 + times[i] <= N + 1){
                    prev_index = i + 1;
                    count += pays[i];
                }else if(prev_index + times[prev_index - 1] <= i + 1){
                    if(i + 1 + times[i] <= N + 1){
                        prev_index = i + 1;
                        count += pays[i];
                    }
                }

            }
        }

        cout << "ans: " << ans;
        ans = max(ans, count);
    }else{
        index_list[index] = false;
        get_max(index + 1);
        index_list[index] = true;
        get_max(index + 1);       
    }
}

int main(void){

    cin >> N;

    for(int i = 0; i < N; i++){
        int t, p;
        cin >> t >> p;

        times.push_back(t);
        pays.push_back(p);
    }

    get_max(0);

    cout << ans;
}
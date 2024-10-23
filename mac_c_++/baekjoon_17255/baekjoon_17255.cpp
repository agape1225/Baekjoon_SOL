#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

string N;
int visited[10] = {0};
char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
int ans = 0;
set<string> prevs;

void get_ans(string str, string prev){
    if(str == ""){
        //시작

        for(int i = 0; i < 10; i++){
            if(visited[nums[i] - '0']){
                string tmp = str + nums[i];
                get_ans(tmp, prev + tmp);
            }
        }

    }else if(str.size() < N.size()){
        for(int i = 0; i < 10; i++){
            if(visited[nums[i] - '0']){
                string tmp = str + nums[i];
                // prev[count] = tmp;
                get_ans(tmp, prev + tmp);

                tmp = nums[i] + str;
                // prev[count] = tmp;

                get_ans(tmp, prev + tmp);
            }
        }
    }else if(str == N){
        if(prevs.find(prev) == prevs.end()){
            ans++;
            prevs.insert(prev);
        }
    }
}

int main(void){

    

    cin >> N;

    for(auto it : N){
        visited[it - '0'] = true;
    }

    get_ans("", "");

    cout << ans;

    return 0;
}
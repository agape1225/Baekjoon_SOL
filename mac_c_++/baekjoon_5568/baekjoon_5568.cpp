#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

string arr[15];
set<string> s;
bool visited[15] = {0};

int N, K;

void get_ans(int count, string str) {
    if(count == K) {
        s.insert(str);
    }else {
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                visited[i] = true;
                get_ans(count + 1, str + arr[i]);
                visited[i] = false;
            }
        }
    }
}

int main(void) {
   

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    get_ans(0, "");

    cout << s.size();

    return 0;
}
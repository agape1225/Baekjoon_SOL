#include <iostream>
#include <string>
#include <set>

using namespace std;

string N;
set<string> dict;

int answer = 0;

void get_count(string str, int start, int end, string history){

    if(str == N && dict.find(history) == dict.end()){
        answer++;
        dict.insert(history);
    }

    if(start > 0)
        get_count(N[start - 1] + str, start - 1, end, history + str);

    if(end < N.size() - 1)
        get_count(str + N[end + 1], start, end + 1, history + str);
}

int main(void){
    
    cin >> N;

    for(int i = 0; i < N.size(); i++){
        string tmp(1, N[i]);
        get_count(tmp, i, i, tmp);
    }

    cout << answer;
}
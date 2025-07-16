/*
시뮬레이션 문제
map을 사용하여 history를 구현한다.(visited대체) o(logN)
모든 경우의 수를 구하면 된다.

---
탐욕으로 접근해야할 것 같다.
경우의 수가 많은 경우를 생각하지 못했다.
필요한 연산 회수를 일일히 계산하는 방식으로 해결해야한다.
*/



#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
#include <iostream>

using namespace std;

bool is_all_ice_bear(vector<int> count) { 
    for(auto it : count) {
        if(it != 0) {
            return false;
        }
    }
    return true;
}

string get_next_bears(string bears, int start_index, int k) {
    string next_bears = bears;
    for(int i = 0; i < k; i++) {
        if(next_bears[start_index + i] == 'Y') {
            next_bears[start_index + i] = 'P';
        }
        else if(next_bears[start_index + i] == 'P') {
            next_bears[start_index + i] = 'I';
        }
        else if(next_bears[start_index + i] == 'I') {
            next_bears[start_index + i] = 'Y';
        }
    }
    return next_bears;
}

bool is_range_all_ice(string bears, int start_index, int k) {
    for(int i = 0; i < k; i++) {
        if(bears[start_index + k] != 'I') {
            return false;
        }
    }
    return true;
}

int solution(string bears, int k) {
    int answer = 0;
    // 필요한 연산 횟수 저장
    vector<int> count(bears.size());
    for(int i = 0; i < bears.size(); i++) {
        if(bears[i] == 'Y') {
            count[i] = 2;
        }
        if(bears[i] == 'P') {
            count[i] = 1;
        }
        if(bears[i] == 'I') {
            count[i] = 0;
        }
    }

    for(int i = 0; i <= bears.size() - k; i++) {
        int current_count = count[i];
        if(current_count == 0) {
            continue;
        }

        answer += current_count;

        for(int j = 0; j < k; j++) {
            count[i + j] = (count[i + j] - current_count + 3) % 3;
        }

    }

    if(!is_all_ice_bear(count)) {
        answer = -1;
    }

    return answer;
}
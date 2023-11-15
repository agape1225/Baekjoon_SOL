#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

//문자열 판별 함수

//문자열 생성 함수

vector<bool> visited;
vector<string> members;
vector<string> global_data;
int answer;

int get_index(string line, char member) {
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == member)
            return i;
    }
}

bool check_line(string line) {
    for (auto it : global_data) {
        int member1 = get_index(line, it[0]);
        int member2 = get_index(line, it[2]);

        if (it[3] == '=') {
            if (abs(member1 - member2) - 1 != (it[4] - '0'))
                return false;
        }
        else if (it[3] == '<') {
            if (abs(member1 - member2) - 1 >= (it[4] - '0'))
                return false;
        }
        else {
            if (abs(member1 - member2) - 1 <= (it[4] - '0'))
                return false;
        }
    }
    return true;
}

void get_line(int max, string line) {
    //검사 시작
    if (max == line.size()) {
        if (check_line(line)) {
            answer++;
        }
    }
    //순서 세우기
    else {
        for (int i = 0; i < 8; i++) {
            if (!visited[i]) {
                visited[i] = true;
                get_line(max, line + members[i]);
                visited[i] = false;
            }
        }
    }
}

int solution(int n, vector<string> data) {
    //전역 변수 초기화
    answer = 0;
    members = { "A", "C", "F", "J", "M", "N", "R", "T" };
    visited = { 0, 0, 0, 0, 0, 0, 0, 0 };
    global_data = data;

    get_line(8, "");

    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.

//���ڿ� �Ǻ� �Լ�

//���ڿ� ���� �Լ�

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
    //�˻� ����
    if (max == line.size()) {
        if (check_line(line)) {
            answer++;
        }
    }
    //���� �����
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
    //���� ���� �ʱ�ȭ
    answer = 0;
    members = { "A", "C", "F", "J", "M", "N", "R", "T" };
    visited = { 0, 0, 0, 0, 0, 0, 0, 0 };
    global_data = data;

    get_line(8, "");

    return answer;
}
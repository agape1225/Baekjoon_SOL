#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int commands[100005] = {0};
int count_commands = 0;
int tmp;

int cache[100005][5][5] = {0};

int get_power(int from, int to) {
    if(from == 0) {
        return 2;
    }

    if(from == to) {
        return 1;
    }

    if(from % 2 == to % 2) {
        return 4;
    }

    return 3;
}

int get_ans(int count, int left, int right) {
    // 종료 조건
    if(count == count_commands) {
        return 0;
    }

    int next_pos = commands[count];
    int tmp = cache[count][left][right];

    if(tmp != 0) {
        return tmp;
    } 

    return cache[count][left][right] = min(
        get_ans(count + 1, left, next_pos) + get_power(right, next_pos),
        get_ans(count + 1, next_pos, right) + get_power(left, next_pos)
    );
}

int main(void) {

    while(true) {
        cin >> tmp;
        if(tmp == 0) {
            break;
        }
        commands[count_commands++] = tmp;
    }

    cout << get_ans(0, 0, 0);

    return 0;

}
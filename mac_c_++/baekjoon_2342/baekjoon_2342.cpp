/*

cache를 왼발과 오른발로 나눈다.. 이게 맞는일 일까?흠.....

*/
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int command[100005] ;
int cache[100005][5][5] = {0};
int len = 1;

int get_point(int from, int to) {

    if(from == to) {
        return 1;
    }

    if(from == 0) {
        return 2;
    }

    //반대편 이라는 뜻!
    if(from % 2 == to % 2) {
        return 4;
    }else {
        return 3;
    }
}

int get_ans(int index, int left, int right) {
    if(index == len - 1) {
        return 0;
    }

    if((left != 0 && right != 0) && left == right) {
        return 987654321;
    }

    if(cache[index][left][right] != -1) {
        return cache[index][left][right];
    }

    return cache[index][left][right] = min(
        get_ans(index + 1, command[index + 1], right) + get_point(left, command[index + 1]),
        get_ans(index + 1, left, command[index + 1]) + get_point(right, command[index + 1])
    );
}

int main(void) {
    int tmp;
    // cache[i][0] = 왼발을 움직였을 때의 정보
    // cache[i][1] = 오른발을 움직였을 때의 정보
    // pair<int, pair<int, int>> cache[100005][2];
    

    cin >> tmp;
    while(tmp != 0) {
        // command.push_back(tmp);
        command[len++] = tmp;
        cin >> tmp;
    }

    // if(command.size() == 0) {
    //     cout << 0;
    //     return 0;
    // }

    for(int i = 0; i <= len; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                cache[i][j][k] = -1;
            }
        }
    }

    cout << get_ans(0, 0, 0);

    return 0;


}
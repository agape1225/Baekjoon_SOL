#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// int get_magic_rock(int storey, int count){
//     //ÀÚ¸®¼ö
//     int num_size = 1;

//     while(storey / (num_size * 10)){
//         num_size *= 10;
//     }
//     //cout << storey << ' ' << count << ' ' << num_size << endl;
//     while(storey){
//         count += storey / num_size;
//         storey %= num_size;
//         num_size /= 10;
//     }
//     return count;
// }

int solution(int storey) {
    int answer = 9876543210;
    queue<pair<int, int>> q;
    q.push(make_pair(storey, 0));

    while (!q.empty()) {
        int current = q.front().first;
        int count = q.front().second;
        q.pop();

        if (current == 0) {
            answer = min(answer, count);
        }
        else {

            if (count + current % 10 <= answer)
                q.push(make_pair(current / 10, count + current % 10));
            if (count + (10 - current % 10) <= answer)
                q.push(make_pair((current + 10) / 10, count + (10 - current % 10)));
        }

    }

    return answer;
}
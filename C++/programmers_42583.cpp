#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    //반복이고 answer는 시간
    int index = 0;
    int weight_sum = 0;
    int queue_begin = 0;
    int queue_end = 0;
    vector<pair<int, int>> q;

    while (index < truck_weights.size() || queue_begin != queue_end) {
        //cout << index << endl; 
        if (queue_begin != queue_end) {
            //cout << answer << ' ';
            for (int i = queue_begin; i < queue_end; i++) {
                //cout << '(' << q[i].first << ',' << q[i].second << ')' << endl; 
                q[i].second--;
                if (q[i].second == 0) {
                    queue_begin++;
                    weight_sum -= q[i].first;
                }
            }
        }
        if (index < truck_weights.size()
            && truck_weights[index] <= weight - weight_sum &&
            queue_end - queue_begin < bridge_length) {

            q.push_back(make_pair(truck_weights[index], bridge_length));
            queue_end++;
            weight_sum += truck_weights[index];
            index++;
        }
        answer++;
    }

    return answer;
}
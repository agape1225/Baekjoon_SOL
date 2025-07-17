#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    priority_queue<int> server_end_times;
    // int server_end_times[25] = {0};
    
    for(int time = 0; time < players.size(); time++) {
        int player_count = players[time];
        if(player_count > 0) {
            int required_room = player_count / m;
            //time으로 server_end_times 업데이트
            while(!server_end_times.empty() && time >= -server_end_times.top()) {
                server_end_times.pop();
            }
            int add_server_count = required_room - server_end_times.size();
            if(add_server_count > 0) {
                answer += add_server_count;
                for(int i = 0; i < add_server_count; i++){
                    server_end_times.push(-(time + k));
                }
            }
            
            
        }
    }
    
    return answer;
}
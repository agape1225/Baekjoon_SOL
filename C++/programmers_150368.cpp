#include <string>
#include <vector>

using namespace std;

int dis_rate[4] = { 10, 20, 30, 40 };
int emoticons_size;

int rates_index[7] = { 0 };
vector<vector<int>> global_users;
vector<int> global_emoticons;
vector<int> answer;

void comb_rate(int index) {
    if (index == emoticons_size) {

        int plus_user = 0;
        int count_cost = 0;

        for (int user = 0; user < global_users.size(); user++) {

            int count = 0.0;

            for (int emoticon = 0; emoticon < emoticons_size; emoticon++) {
                if (global_users[user][0] <= dis_rate[rates_index[emoticon]]) {
                    count += global_emoticons[emoticon]
                        * (100.0 - dis_rate[rates_index[emoticon]]) / 100;
                }
            }

            if (count >= global_users[user][1])
                plus_user++;
            else
                count_cost += count;
        }

        if (answer.size() == 0) {
            answer.push_back(plus_user);
            answer.push_back(count_cost);
        }
        else if (answer[0] < plus_user || (answer[0] == plus_user && answer[1] < count_cost)) {
                answer[0] = plus_user;
                answer[1] = count_cost;
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            rates_index[index] = i;
            comb_rate(index + 1);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {

    emoticons_size = emoticons.size();
    global_users = users;
    global_emoticons = emoticons;

    comb_rate(0);

    return answer;
}
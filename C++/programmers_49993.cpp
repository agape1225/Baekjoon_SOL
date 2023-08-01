#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (auto skill_tree : skill_trees) {
        string skill_orders = skill;
        int index = 0;
        int dir = true;

        for (int i = 0; i < skill_tree.size(); i++) {
            if (skill_orders.find(skill_tree[i]) != string::npos) {

                if (skill_tree[i] == skill_orders[index]) {
                    index++;
                }
                else {
                    dir = false;
                    break;
                }
            }
        }
        if (dir)
            answer++;
    }
    return answer;
}
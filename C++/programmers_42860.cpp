#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string name) {
    int answer = 0;
    queue<pair<int, pair<int, string>>> q;
    string str = "";

    for (int i = 0; i < name.size(); i++) {
        str += "A";
    }

    q.push(make_pair(0, make_pair(0, str)));

    while (true) {

        int index = q.front().first;
        int count = q.front().second.first;
        string name_tmp = q.front().second.second;

        q.pop();

        //해당 문자열 맞추기
        char current = name_tmp[index];
        char goal = name[index];
        int count_tmp = 0;

        if (current < goal)
            count_tmp = min(goal - current, (current - 'A') + 1 + ('Z' - goal));
        else
            count_tmp = min(current - goal, (goal - 'A') + 1 + ('Z' - current));

        name_tmp[index] = name[index];
        count += count_tmp;

        if (name_tmp == name) {
            answer = count;
            break;
        }

        //왼쪽으로 한번 가기
        if (index == 0)
            q.push(make_pair(name.size() - 1, make_pair(count + 1, name_tmp)));
        else 
            q.push(make_pair(index - 1, make_pair(count + 1, name_tmp)));

        //오른쪽으로 한번 가기
        if (index == name.size() - 1)
            q.push(make_pair(0, make_pair(count + 1, name_tmp)));
        else
            q.push(make_pair(index + 1, make_pair(count + 1, name_tmp)));

    }

    return answer;
}
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool is_lion_win(vector<pair<int, vector<int>>> cache) {
    for (int i = 0; i < cache.size(); i++) {
        if (cache[i].first > 0)
            return false;
    }
    return true;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int max = -1;
    vector<int> tmp = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    vector<pair<int, vector<int>>> cache;
    queue<
        pair<int,
        pair<vector<int>, int>>> q;

    q.push(make_pair(0, make_pair(tmp, n)));

    while (!q.empty()) {

        int index = q.front().first;
        vector<int> target = q.front().second.first;
        int arraw = q.front().second.second;

        q.pop();

        //점수 계산하기
        if (arraw == 0 || index == 11) {

            int apache = 0;
            int lion = 0;

            for (int i = 0; i < 11; i++) {
                if (info[i] == 0 && target[i] == 0)
                    continue;
                if (info[i] >= target[i])
                    apache += 10 - i;
                else
                    lion += 10 - i;
            }

            cache.push_back(make_pair(lion - apache, target));
        }
        //0으로 할지 안 할지
        else {

            if (info[index] + 1 <= arraw) {
                int buff = target[index];
                target[index] = info[index] + 1;
                q.push(make_pair(index + 1, make_pair(target, arraw - (info[index] + 1))));
                target[index] = buff;
            }

            if (index == 10) {
                int buff = target[index];
                target[index] = arraw;
                q.push(make_pair(index + 1, make_pair(target, 0)));
                target[index] = buff;

            }
            else
                q.push(make_pair(index + 1, make_pair(target, arraw)));
        }
    }

    //라이언이 우승할 방법이 없는지를 체크
    if (is_lion_win(cache))
        return { -1 };

    for (int i = 0; i < cache.size(); i++) {
        if (max == -1) {
            max = cache[i].first;
            answer = cache[i].second;
        }
        else if (max <= cache[i].first) {
            max = cache[i].first;
            answer = cache[i].second;
        }
    }
    return answer;
}
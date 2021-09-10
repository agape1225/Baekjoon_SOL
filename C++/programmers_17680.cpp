#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    vector<string> memory;

    for (auto it = cities.begin(); it != cities.end(); it++) {

        transform((*it).begin(), (*it).end(), (*it).begin(), ::tolower);

        auto fi = find(memory.begin(), memory.end(), *it);

        // 값이 있을 때
        if (fi != memory.end()) {

            answer += 1;
            memory.erase(fi);

        }
        else {  // 값이 없을 때

            answer += 5;

        }

        memory.push_back(*it);

        if (memory.size() > cacheSize) {
            memory.erase(memory.begin());
        }

    }

    return answer;
}
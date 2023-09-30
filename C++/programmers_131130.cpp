#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cache[100] = { 0 };

int create_set(int node, vector<int> cards) {

    int count = 1;
    int root = node;
    int next = cards[root];
    
    while (cache[next] != root) {
        count++;
        cache[next] = root;
        next = cards[next];
    }

    return count;
}

int solution(vector<int> cards) {

    int answer = 0;
    vector<int> set_counts;

    for (int i = 0; i < cards.size(); i++) {
        cache[i] = i;
        cards[i]--;
    }

    for (int i = 0; i < cards.size(); i++) {
        if (cache[i] == i) {
            int buff = create_set(i, cards);
            set_counts.push_back(buff);
        }
    }

    if (set_counts.size() > 1) {
        sort(set_counts.begin(), set_counts.end());
        answer = set_counts[set_counts.size() - 1] * set_counts[set_counts.size() - 2];
    }

    return answer;
}
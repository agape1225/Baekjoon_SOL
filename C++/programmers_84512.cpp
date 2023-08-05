#include <string>
#include <vector>

using namespace std;

vector<string> dict;
vector<string> stand = { "A", "E", "I", "O", "U" };

void get_make_dict(int index, string prev) {
    if (prev.size() == 5)
        return;

    for (int i = index; i < stand.size(); i++) {
        string tmp = prev + stand[i];
        dict.push_back(tmp);
        get_make_dict(index, tmp);
    }
}

int solution(string word) {
    int answer = 0;

    get_make_dict(0, "");

    for (int i = 0; i < dict.size(); i++) {
        if (word == dict[i]) {
            answer = i;
            break;
        }
    }

    return answer;
}
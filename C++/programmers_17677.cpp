#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    vector<string> inter_strs_1;
    vector<string> inter_strs_2;

    vector<string> union_strs_1;
    vector<string> union_strs_2;

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    for (int i = 0; i < str1.size() - 1; i++) {

        if ('A' <= str1[i] && str1[i] <= 'Z' && 'A' <= str1[i + 1] && str1[i + 1] <= 'Z') {
            inter_strs_1.push_back(str1.substr(i, 2));
            union_strs_1.push_back(str1.substr(i, 2));
        }


    }

    for (int i = 0; i < str2.size() - 1; i++) {

        if ('A' <= str2[i] && str2[i] <= 'Z' && 'A' <= str2[i + 1] && str2[i + 1] <= 'Z') {
            inter_strs_2.push_back(str2.substr(i, 2));
            union_strs_2.push_back(str2.substr(i, 2));
        }

    }

    double inters = 0;
    double unions = 0;

    for (auto it = inter_strs_1.begin(); it != inter_strs_1.end(); it++) {

        auto buff = find(inter_strs_2.begin(), inter_strs_2.end(), *it);
        if (buff != inter_strs_2.end()) {
            inters++;
            inter_strs_2.erase(buff);
        }

    }

    for (auto it = union_strs_1.begin(); it != union_strs_1.end(); it++) {
        unions++;
        auto buff = find(union_strs_2.begin(), union_strs_2.end(), *it);
        if (buff != union_strs_2.end()) {
            union_strs_2.erase(buff);
        }
    }

    unions += union_strs_2.size();

    if (unions == 0 && inters == 0)
        return 65536;
    double tmp = inters / unions;
    answer = tmp * 65536;

    return answer;
}
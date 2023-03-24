#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int left = 0;

    for (int right = people.size() - 1; right >= 0; right--) {

        if (left > right)
            break;
        if (people[left] + people[right] <= limit)
            left++;
        answer++;

    }


    return answer;
}
#include <string>
#include <vector>
#include <set>

using namespace std;

int left_cache[10001] = { 0 };
int right_cache[10001] = { 0 };

int solution(vector<int> topping) {
    int answer = 0;

    int left_size = 0;
    int right_size = 0;

    left_cache[topping[0]]++;
    left_size++;

    for (int i = 1; i < topping.size(); i++) {
        int num = topping[i];

        if (right_cache[num] == 0) {
            right_size++;
        }
        right_cache[num]++;
    }

    if (left_size == right_size)
        answer++;

    for (int i = 1; i < topping.size(); i++) {

        int num = topping[i];

        if (left_cache[num] == 0) {

            left_size++;

        }

        left_cache[num]++;
        right_cache[num]--;

        if (right_cache[num] == 0) 
            right_size--;
        

        if (left_size == right_size)
            answer++;
    }

    return answer;
}
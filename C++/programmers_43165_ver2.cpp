#include <string>
#include <vector>

using namespace std;

int get_num(vector<int> numbers, int target, int index, int num) {

    if (index == numbers.size()) {

        if (target == num)
            return 1;
        else
            return 0;

    }

    return get_num(numbers, target, index + 1, num + numbers[index]) + get_num(numbers, target, index + 1, num - numbers[index]);

}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer = get_num(numbers, target, 0, 0);

    return answer;
}
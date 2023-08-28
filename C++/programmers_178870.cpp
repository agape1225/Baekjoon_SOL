#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int sum = sequence[0];
    int start_index = 0;
    int end_index = 0;

    int start_ans = -1;
    int end_ans = -1;


    while (end_index < sequence.size() && start_index <= end_index) {

        if (sum == k) {
            if (start_ans == -1 && end_ans == -1) {
                start_ans = start_index;
                end_ans = end_index;
            }
            else if (end_ans - start_ans > end_index - start_index) {
                start_ans = start_index;
                end_ans = end_index;
            }
            else if (end_ans - start_ans == end_index - start_index &&
                start_ans > start_index) {
                start_ans = start_index;
                end_ans = end_index;
            }
            sum -= sequence[start_index];
            start_index++;
        }

        if (sum < k) {
            end_index++;
            sum += sequence[end_index];
        }
        else {
            sum -= sequence[start_index];
            start_index++;
        }
    }
    answer.push_back(start_ans);
    answer.push_back(end_ans);

    return answer;
}
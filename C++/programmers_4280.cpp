#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> student;
    int ans1[5] = { 1,2,3,4,5 };
    int ans2[8] = { 2,1,2,3,2,4,2,5 };
    int ans3[10] = { 3,3,1,1,2,2,4,4,5,5 };

    int index_1 = 0;
    int index_2 = 0;
    int index_3 = 0;

    student.push_back(0);
    student.push_back(0);
    student.push_back(0);

    for (int i = 0; i < answers.size(); i++) {

        if (answers[i] == ans1[index_1]) {
            student[0]++;
        }

        if (answers[i] == ans2[index_2]) {
            student[1]++;
        }

        if (answers[i] == ans3[index_3]) {
            student[2]++;
        }

        index_1 = (index_1 + 1) % 5;
        index_2 = (index_2 + 1) % 8;
        index_3 = (index_3 + 1) % 10;

    }

    int max = -1;

    for (int i = 0; i < 3; i++) {
        if (max < student[i])
            max = student[i];
    }

    for (int i = 0; i < 3; i++) {

        if (student[i] == max)
            answer.push_back(i + 1);

    }

    return answer;
}
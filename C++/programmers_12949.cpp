#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    int row = arr1.size();
    int col = arr2.begin()->size();

    for (int i = 0; i < row; i++) {
        //기준점은 row
        vector<int> tmp_row;

        for (int j = 0; j < col; j++) {
            
            int tmp_num = 0;

            for (int k = 0; k < arr2.size(); k++)
                tmp_num += arr1[i][k] * arr2[k][j];
            
            tmp_row.push_back(tmp_num);

        }
        answer.push_back(tmp_row);
    }


    return answer;
}
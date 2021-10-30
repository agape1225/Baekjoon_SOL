#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define SIZE 100

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<int> procession[SIZE];
    int count = 1;

    int start_row, start_col, end_row, end_col;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            procession[i].push_back(count++);
    }

    for (int i = 0; i < queries.size(); i++) {

        vector<int> nums;
        start_row   = queries[i][0] - 1;
        start_col   = queries[i][1] - 1;
        end_row     = queries[i][2] - 1;
        end_col     = queries[i][3] - 1;
        int buff = procession[start_row][start_col];
        int tmp;

        //cout << buff << endl << endl;

        // up
        for (int j = start_col + 1; j <= end_col; j++) {

            tmp = procession[start_row][j];
            procession[start_row][j] = buff;
            nums.push_back(buff);
            buff = tmp;

        }

        //right
        for (int j = start_row + 1; j <= end_row; j++) {

            tmp = procession[j][end_col];
            procession[j][end_col] = buff;
            nums.push_back(buff);
            buff = tmp;
                
        }

        // bottom
        for (int j = end_col - 1; j >= start_col; j--) {

            tmp = procession[end_row][j];
            procession[end_row][j] = buff;
            nums.push_back(buff);
            buff = tmp;

        }

        //left
        for (int j = end_row - 1; j >= start_row; j--) {

            tmp = procession[j][start_col];
            procession[j][start_col] = buff;
            nums.push_back(buff);
            buff = tmp;
        }

        int min = *min_element(nums.begin(), nums.end());

        //cout << min << endl;

        /*for (int k = 0; k < rows; k++) {
            for (int l = 0; l < columns; l++) {
                cout.width(3);
                cout << procession[k][l] << ' ';
            }
            cout << '\n';
        }

        cout << endl << endl;*/

        answer.push_back(min);

    }

    

    return answer;
}

int main(void) {

    vector<vector<int>> queries = {
        {2,2,5,4}
        ,{3,3,6,6}
        ,{5,1,6,3}
    };

    solution(6, 6, queries);

}
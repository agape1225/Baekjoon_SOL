#include <string>
#include <vector>
#include <iostream>

using namespace std;

int triangle[1000][1000];
int tmp = 6;

void draw_triangle(int start_row, int start_col, int start_num, int size) {

    //cout << start_row << ' ' << start_col << ' ' << size << ' ' << start_num << endl;
    for (int i = start_row; i < start_row + size; i++) {
        triangle[i][start_col] = start_num;
        start_num++;
    }

    /*for (int i = 0; i < tmp; i++) {
        for (int j = 0; j < tmp; j++) {
            cout << triangle[i][j] << ' ';
        }
        cout << endl;
    }*/

    for (int i = start_col + 1; i < start_col + size; i++) {
        triangle[start_row + size - 1][i] = start_num;
        start_num++;
    }
    int index_row = start_row + size - 2;
    int index_col = start_col + size - 2;

    /*for (int i = 0; i < tmp; i++) {
        for (int j = 0; j < tmp; j++) {
            cout << triangle[i][j] << ' ';
        }
        cout << endl;
    }*/

    while (start_row < index_row && start_col < index_col) {
        triangle[index_row][index_col] = start_num;
        index_row--;
        index_col--;
        start_num++;
    }

    /*cout << "--------------" << endl;

    for (int i = 0; i < tmp; i++) {
        for (int j = 0; j < tmp; j++) {
            cout << triangle[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "--------------" << endl;*/

    if (size - 3 > 0) {
        //cout << start_row + 2 << ' ' << start_col + 1 << ' ' << size - 3 << ' ' << start_num << endl;
        draw_triangle(start_row + 2, start_col + 1, start_num, size - 3);
    }

}

vector<int> solution(int n) {
    vector<int> answer;

    draw_triangle(0, 0, 1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(triangle[i][j]);
        }
    }

    return answer;
}
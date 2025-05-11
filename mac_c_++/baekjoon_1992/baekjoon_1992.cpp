#include <iostream>
#include <algorithm>

using namespace std;

int arr[100][100] = {0};

int get_digit(int row, int col, int size) {
    int num = -1;
    int count_one = 0;
    int count_zero = 0;

    for(int i = row; i < row + size; i++) {
        for(int j = col; j < col + size; j++) {
            if(arr[i][j] == 0) {
                count_zero++;
            }else {
                count_one++;
            }
        }
    }

    if(count_zero == size * size) {
        return 0;
    }else if(count_one == size * size) {
        return 1;
    }else {
        return -1;
    }
}

void print_tree(int row, int col, int size) {
    

    int digit = get_digit(row, col, size);
    if(digit != -1) {
        cout << digit;
    }else {
        cout << '(';
        int next_size = size / 2;
        print_tree(row, col, next_size);
        print_tree(row, col + next_size, next_size);
        print_tree(row + next_size, col, next_size);
        print_tree(row + next_size, col + next_size, next_size);
        cout << ')';
    }


    
}

int main(void) {

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp - '0';
            // cin >> arr[i][j];
        }
    }

    // cout << "1";

    print_tree(0, 0, N);

    return 0;


}
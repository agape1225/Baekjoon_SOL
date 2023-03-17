#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans = 0;
int print_arr[1001] = { 0 };

void get_num(int start, int input, int max, int index) {
    if (input == max) {
        for (int i = start; i <= max; i++) {
            //get_num(i + 1, input - i, max);
            print_arr[index] = i;
            if (input - i >= 0) {
                get_num(i + 1, input - i, max, index + 1);
            }
            else if (input - 1 < 0) {
                break;
            }
        }
    }
    else if (input == 0) {
        if (input == 0) {
            ans++;
            /*for(int i = 0; i <= index; i++){
                cout << print_arr[i] << ' ';
            }
            cout << endl;*/
        }

    }
    else if (input > 0) {
        get_num(start + 1, input - start, max, index + 1);
    }
}

int solution(int n) {
    int answer = 0;

    get_num(1, n, n, 0);
    answer = ans;

    return answer;
}
#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 9

using namespace std;

int main(void) {
    int max_num;
    int max_index;
    int tmp;

    for(int i = 0; i < SIZE; i++) {
        cin >> tmp;
        
        if(i == 0) {
            max_num = tmp;
            max_index = i + 1;
        }else if(max_num < tmp) {
            max_num = tmp;
            max_index = i + 1;
        }
    }

    cout << max_num << ' ' << max_index;

    return 0;


}
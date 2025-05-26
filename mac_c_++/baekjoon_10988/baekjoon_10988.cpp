#include <iostream>
#include <algorithm>

using namespace std;

bool is_pal(string str) {

    int left = 0;
    int right = str.size() - 1;

    while(left <= right) {
        if(str[left] != str[right]) {
            return false;
        }

        left ++;
        right --;
    }

    return true;

}

int main(void) {

    string str;
    cin >> str;

    if(is_pal(str)) {
        cout << 1;
    }else {
        cout << 0;
    }

}
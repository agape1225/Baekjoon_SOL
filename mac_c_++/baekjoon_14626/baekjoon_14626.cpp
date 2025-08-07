#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    // cout << '0' - '0';
    string isbn;
    int sum = 0;
    int nums[10] = {'0', '1','2','3','4','5','6','7','8','9'};
    int ans = -1;

    cin >> isbn;

    for(auto it : nums) {
        sum = 0;
        for(int i= 0; i < isbn.size() - 1; i++) {
            char num = isbn[i];
        if(isbn[i] == '*') {
            num = it;
        }

        if((i + 1) % 2) {
            sum += num - '0';
        }else {
            sum += (num - '0') * 3;
        }
        // cout << sum << endl;

        }
        // cout << "-----------" << endl;

        
           
        // if(it == '9') {
        // cout << sum << endl;
        // cout << isbn[isbn.size() - 1] - '0' << endl;
        // cout << sum << endl;
        // }
        if(isbn[isbn.size() - 1] - '0' == (10 - (sum % 10)) % 10) {
        ans = it - '0';
        break;
        }
    }

    

    cout << ans;
// 3 = 10 - (142 + x) % 10
    return 0;


}
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    int buttons[1000005] = {0};
    int count = 0;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> buttons[i];
    }

    for(int i = 0; i < N; i++) {
        if(buttons[i] == 1) {
            count++;

            buttons[i] = 0;
            if(i + 1 < N)
                buttons[i + 1] = buttons[i+1] == 1 ? 0 : 1;
            if(i + 2 < N)
                buttons[i + 2] = buttons[i+2] == 1 ? 0 : 1;
        }
    }

    cout << count;

    return 0;


}
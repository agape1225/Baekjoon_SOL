#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main(void) {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        multiset<int> ms;
        char cmd;
        int n, k;

        cin >> k;

        for(int i = 0; i < k; i++) {
            cin >> cmd >> n;

            if(cmd == 'I') {

                ms.insert(n);

            }else if(cmd == 'D') {
                if(!ms.empty()) {
                    if(n == 1) {
                        ms.erase(--ms.end());    
                    }else if(n == -1) {
                        ms.erase(ms.begin());
                    }      
                }

            }
        }

        if(ms.empty()) {
            cout << "EMPTY" << '\n';
        }else {
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
        }


    }
}
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    int B, C;
    int arr[1000005] = {0};
    long long count = 0;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> B >> C;

    for(int i = 0; i < N; i++) {
        arr[i] -= B;
        count++;

        if(arr[i] > 0) {
            int tmp = arr[i] / C;
            if(arr[i] % C > 0) {
                count += tmp + 1;
            }else {
                count += tmp;
            }
        }
    }

    cout << count;

    



    

    return 0;




}
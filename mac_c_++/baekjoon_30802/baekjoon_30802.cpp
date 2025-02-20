#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int N, P;
    double T;
    int arr[6];
    int count_group = 0;

    cin >> N;

    for(int i  = 0 ; i < 6; i++) {
        cin >> arr[i];
    }

    cin >> T >> P;

    for(int i = 0; i < 6; i++) {
        // int count;
        // cin >> count;
        // cout << ceil(arr[i] / T) << endl;



        count_group += int(ceil(arr[i] / T));
    }

    cout << count_group << endl;
    cout << N / P << ' ' << N  % P;

    return 0;
}
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long arr[5000];
long long ans[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num;
    long long result = 3000000001;
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    sort(arr, arr + num);
    for (int k = 0; k < num - 2; k++) {
        int l = k + 1, r = num - 1;
        while (l < r) {
            long long val = arr[k] + arr[l] + arr[r];
            if (abs(val) < result) {
                result = abs(val);
                ans[0] = arr[k];
                ans[1] = arr[l];
                ans[2] = arr[r];
                //Ã³¸®
            }
            if (val < 0) l++;
            else r--;
        }
    }
    for (int i = 0; i < 3; i++)
        cout << ans[i] << " ";
    return 0;
}
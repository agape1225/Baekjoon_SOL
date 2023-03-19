#include <string>
#include <vector>

using namespace std;

int cache[100001];

int ans(int n) {
    int num1;
    int num2;

    if (cache[n - 1] != -1) {
        num1 = cache[n - 1];
    }
    else {
        num1 = ans(n - 1);
    }

    if (cache[n - 2] != -1) {
        num2 = cache[n - 2];
    }
    else {
        num2 = ans(n - 2);
    }

    return cache[n] = (num1 + num2) % 1234567;
}

int solution(int n) {
    //int answer = 0;
    for (int i = 0; i < 100001; i++) {
        cache[i] = -1;
    }
    cache[0] = 0;
    cache[1] = 1;
    return ans(n);

}
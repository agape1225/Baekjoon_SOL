#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <ctime>
#include <string.h>
 
using namespace std;
 
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
 
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
 
int main(void)
{
    int t, m, n, x, y, i, j;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d %d %d %d", &m, &n, &x, &y);
        int limit = lcm(m, n);
        for (j = x; j <= limit; j += m) {
            int temp = (j%n == 0) ? n : j % n;
            if (temp == y) {
                printf("%d\n", j);
                break;
            }
        }
        if (j > limit)
            printf("-1\n");
    }
    return 0;
}

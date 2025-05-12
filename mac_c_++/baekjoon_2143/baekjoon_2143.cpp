#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int T;
int A[1000];
int B[1000];

vector<long long> cache_a;
vector<long long> cache_b;

long long ans = 0;

int n, m;

void init_cache() {
    for(int i = 0; i < n; i++) {
        cache_a.push_back(A[i]);
        long long tmp = A[i];
        for(int j = i + 1; j < n; j++) {
            tmp += A[j];
            cache_a.push_back(tmp);
        }
    }

    for(int i = 0; i < m; i++) {
        cache_b.push_back(B[i]);
        long long tmp = B[i];
        for(int j = i + 1; j < m; j++) {
            tmp += B[j];
            cache_b.push_back(tmp);
        }
    }
}

void set_ans() {
    for(auto it : cache_a) {
        int tmp = T - it;
        auto lo = lower_bound(cache_b.begin(), cache_b.end(), tmp);
        auto up = upper_bound(cache_b.begin(), cache_b.end(), tmp);

        ans += up - lo;
    }
}

int main(void) {

    // int ans = 0;
    
    cin >> T;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> B[i];
    }

    // set cache
    init_cache();

    sort(cache_b.begin(), cache_b.end());

    set_ans();

    cout << ans;

    return 0;
    
}
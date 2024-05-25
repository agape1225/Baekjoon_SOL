#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(char a, char b){
    return a> b;
}

long long solution(long long n) {
    long long answer = 0;
    string cache = to_string(n);
    
    sort(cache.begin(), cache.end(), comp);
    
    return stoll(cache);
}

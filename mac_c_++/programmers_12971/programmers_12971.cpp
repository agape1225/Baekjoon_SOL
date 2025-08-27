#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int cache[100005] = {0};
    
    if(sticker.size() == 1) {
        return sticker[0];
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // cout << "Hello Cpp" << endl;
    cache[0] = sticker[0];
    cache[1] = sticker[0];
    
    for(int i = 2; i < sticker.size() - 1; i++) {
        cache[i] = max(cache[i - 2] + sticker[i], cache[i - 1]);
    }
    answer = cache[sticker.size() - 2];
    
    cache[0] = 0;
    cache[1] = sticker[1];
    
    for(int i = 2; i < sticker.size(); i++) {
        cache[i] = max(cache[i - 2] + sticker[i], cache[i - 1]);
    }
    
    answer = max(answer, cache[sticker.size() - 1]);

    return answer;
}
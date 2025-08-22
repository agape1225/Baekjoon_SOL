#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    int end = -1;
    float required_range = w * 2 + 1;
    float range;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    // cout << "Hello Cpp" << endl;
    
    for(auto it : stations) {
        
        end = it - w - 1;
//         if(end >= start) {
                    
//         }
        

        range = end - start + 1;
        // cout << range << ' ' << ceil(range / required_range) << endl;
        if(range > 0) {
            answer += ceil(range / required_range);
        }

        start = it + w + 1;
    }
    
    if(start <= n) {
        answer += ceil((n - start + 1) / required_range);
    }

    return answer;
}
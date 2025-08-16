#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int index = 0;
    
    //가장 작은 차이로..?
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(int i = 0; i < A.size(); i++) {
        if(A[index] < B[i]) {
            index++;
            answer++;
        }
    }
    
    return answer;
}
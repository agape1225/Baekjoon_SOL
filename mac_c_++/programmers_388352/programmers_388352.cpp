#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    for(int num1 = 1; num1 <= n - 4; num1++) {
        for(int num2 = num1 + 1; num2 <= n - 3; num2++) {
            for(int num3 = num2 + 1; num3 <= n - 2; num3++) {
                for(int num4 = num3 + 1; num4 <= n - 1; num4++) {
                    for(int num5 = num4 + 1; num5 <= n; num5++) {
                        vector<int> tmp = {num1, num2, num3, num4, num5};
                        bool is_ans = true;
                        
                        for(int i = 0; i < q.size(); i++) {
                            int count_num = 0;
                            for(int j = 0; j < 5; j++) {
                                if(find(tmp.begin(), tmp.end(), q[i][j]) != tmp.end()) {
                                    count_num++;
                                }
                            }
                            
                            if(count_num != ans[i]) {
                                is_ans = false;
                                break;
                            }
                        }
                        
                        if(is_ans) {
                            answer++;
                        }
                    }
                }
                
            }
            
        }
    }
    
    return answer;
}
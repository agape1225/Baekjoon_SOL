#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 987654321;
    int dp[50][150] = {0};
    
    for(int i = 0; i <= info.size(); i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = 987654321;
        }
    }
    
    dp[0][0] = 0;
    
    for(int i = 0; i < info.size(); i++) {
        
        for(int j = 0; j < m; j++) {
            dp[i + 1][j] = min(dp[i][j] + info[i][0], dp[i + 1][j]);
            
            if(j + info[i][1] < m) {
                dp[i + 1][j + info[i][1]] = min(dp[i][j], dp[i + 1][j + info[i][1]]);
            }
        }
    }
    
    for(int i = 0; i < m; i++) {
        answer = min(dp[info.size()][i], answer);
    }
    
    if(answer >= n) {
        answer = -1;
    }
    
    return answer;
}
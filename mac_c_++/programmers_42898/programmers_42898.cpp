#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    bool is_puddle[105][105] = {0};
    //cache
    int count_route[105][105] = {0};
    bool visited[105][105] = {0};
    
    //map set
    for(auto it : puddles) {
        is_puddle[it[0]][it[1]] = true;
    }
    
    count_route[1][1] = 1;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            
            if((i == 1&& j == 1) || is_puddle[i][j]) {
                continue;
            }
            // int tmp = 0;
            // if(!is_puddle[i - 1][j]) {
            //     tmp += count_route[i - 1][j] % 1000000007;
            // }
            // if(!is_puddle[i][j - 1]) {
            //     tmp += count_route[i][j - 1] % 1000000007;
            // }
            
            count_route[i][j] = (count_route[i - 1][j] +  count_route[i][j - 1]) % 1000000007;
            
            
        }
    }
    
    
    
    
    
    return count_route[m][n];
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int cache[505][505] = {0};
    
    cache[0][0] = triangle[0][0];
    
    if(triangle.size() > 1){
        cache[1][0] = cache[0][0] + triangle[1][0];
        cache[1][1] = cache[0][0] + triangle[1][1];
    }
    
    for(int i = 2; i < triangle.size(); i++){
        for(int j = 0; j < triangle[i].size(); j++){
            if(j == 0)
                cache[i][j] = cache[i - 1][j] + triangle[i][j];
            else {
                cache[i][j] = max(cache[i - 1][j - 1], cache[i - 1][j]) + triangle[i][j]; 
            }
        }
    }
    
    for(int i = 0; i < triangle[triangle.size() - 1].size() ; i++){
        answer = max(answer, cache[triangle.size() - 1][i]);
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    int max_alp_req = 0;
    int max_cop_req = 0;
    
    for(auto it : problems) {
        max_alp_req = max(max_alp_req, it[0]);
        max_cop_req = max(max_cop_req, it[1]);
    }
    
    vector<vector<int>> cache(max_alp_req + 5, vector<int> (max_cop_req + 5, 987654321));
    
    alp = min(alp, max_alp_req);
    cop = min(cop, max_cop_req);
    
    if(alp >= max_alp_req && cop >= max_cop_req) {
        return answer;
    }
    
    cache[alp][cop] = 0;
    
    for(int i = alp; i <= max_alp_req; i++) {
        for(int j = cop; j <= max_cop_req; j++) {
            
            if(cache[i][j] == 987654321) {
                continue;
            }
            
            if(i + 1 <= max_alp_req) {
                cache[i + 1][j] = min(cache[i + 1][j], cache[i][j] + 1);    
            }
            
            if(j + 1 <= max_cop_req) {
                cache[i][j + 1] = min(cache[i][j + 1], cache[i][j] + 1);    
            }
            
            
            for(auto it : problems) {
                int req_alp = it[0];
                int req_cop = it[1];
                int add_alp = it[2];
                int add_cop = it[3];
                int cost = it[4];
                
                if(req_alp <= i && req_cop <= j) {
                    int next_alp = min(max_alp_req, i + add_alp);
                    int next_cop = min(max_cop_req, j + add_cop);
                    
                    cache[next_alp][next_cop] = min(
                        cache[next_alp][next_cop],
                        cache[i][j] + cost
                    );
                }
                
                
            }
            
        }
    }
    
    
    
    return cache[max_alp_req][max_cop_req];
}
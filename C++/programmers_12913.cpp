#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int size = land.size();
    
    for(int i = 0; i < size - 1; i++){
        
        land[i + 1][0] += max(land[i][1], max(land[i][2], land[i][3]));
        land[i + 1][1] += max(land[i][0], max(land[i][2], land[i][3]));
        land[i + 1][2] += max(land[i][1], max(land[i][0], land[i][3]));
        land[i + 1][3] += max(land[i][1], max(land[i][2], land[i][0]));
        
    }
    
    for(int i = 0; i < 4; i++){
        answer = max(answer, land[size - 1][i]);
    }


    return answer;
}

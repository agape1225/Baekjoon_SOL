#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    int start_x = startX;
    int start_y = startY;
    
    for(auto ball : balls){
        int next_x = ball[0];
        int next_y = ball[1];
        
        if(start_x == next_x){
                int d1 = (next_y - start_y) * (next_y - start_y) + 4 * start_x * start_x;
                int d2 = (next_y - start_y) * (next_y - start_y) + 4 * (m - start_x) * (m - start_x);

                int d3;
            
            if (start_y < next_y){
                d3 = (start_y + next_y) * (start_y + next_y);
            }  else {
                d3 = (2 * n - start_y - next_y) * (2 * n - start_y - next_y);
            }
                answer.push_back(min(min(d1, d2), d3));
        }else if(start_y == next_y){
            int d1 = (next_x - start_x) * (next_x - start_x) + 4 * startY * startY;
            int d2 = (next_x - start_x) * (next_x - start_x) + 4 * (n - startY) * (n - startY);
            int d3;
            if (start_x < next_x){
                d3 = (start_x + next_x) * (start_x + next_x);
            } else{
                d3 = (2 * m - start_x - next_x) * (2 * m - start_x - next_x);
            } 
            answer.push_back(min(min(d1, d2), d3));
            
        }else{
            
            int d1 = (next_x - start_x) * (next_x - start_x) + (next_y + startY) * (next_y + startY);
            int d2 = (next_x + start_x) * (next_x + start_x) + (next_y - startY) * (next_y - startY);
            int d3 = (next_y - startY) * (next_y - startY) + (2 * m - start_x - next_x) * (2 * m - start_x - next_x);
            int d4 = (next_x - start_x) * (next_x - start_x) + (2 * n - startY - next_y) * (2 * n - startY - next_y);
            answer.push_back(min(min(d1, d2), min(d3, d4)));

        }
    }
    
    return answer;
}

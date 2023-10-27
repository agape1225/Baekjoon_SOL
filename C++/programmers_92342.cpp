#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> tmp;
    queue<pair<int, pair<int, int>>> q;
    
    for(int i = 0; i < info.size(); i++){
        tmp.push_back(0);
    }
    
    q.push_back(make_pair(tmp, n));
    
    while(!q.emtpy()){
        
        int index = q.front().first;
        int count = q.front().second.first;
        int arraw = q.front().second.second;
        q.pop();
        
        if(index == info.size()){
            //계산
        }
        
        if(info[index] + 1 <= arraw){
            q.push(
                make_pair(index + 1, 
                          make_pair(count + (10 - index), arraw - (info[index] + 1))));
        }
        
        q.push(make_pair)
        
        
        
    }
    
    
    
    return answer;
}

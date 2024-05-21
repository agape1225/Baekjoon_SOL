#include <string>
#include <vector>


//n미터의 벽

//1부터 N까지 구역

//롤러의 길이는 M임

//3456 -> 1234 
//13
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    vector<pair<int,int>> v;
    //시작과 끝
    int start = section[0];
    int end = start + m - 1;
    v.push_back({start,end});
    
    answer = 1;
    
    for(int i = 0;i<section.size();i++){
        if(section[i] > end){
            answer++;
            start = section[i];
            end = start + m - 1;
        }
    }
    
    return answer;
}

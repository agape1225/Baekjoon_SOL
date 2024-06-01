#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int mid = s.size() / 2;
    
    //even
    if(s.size() % 2 == 0){
        answer = s.substr(mid - 1, 2);
    }
    //odd
    else{
        answer = s[mid];
    }
    
    return answer;
}

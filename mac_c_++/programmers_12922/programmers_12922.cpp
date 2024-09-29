#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string chars[2] = {"수", "박"};
    
    for(int i = 0; i < n; i++){
        answer += chars[i % 2];
    }
    
    return answer;
}
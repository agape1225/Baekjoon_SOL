#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    //list로 만든다.
    vector<string> str_list = get_str_list(s);
    for(auto it : str_list){
        if("0" <= it && it <= "9" ){
            answer = (answer * 10) + stoi(it); 
        }else{
            
        }
    }
    return answer;
}

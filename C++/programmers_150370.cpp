#include <string>
#include <vector>

using namespace std;

int get_term_date(vector<string> terms, string term){
    for(auto it : terms){
        if(it[0] == term){
            return stoi(it[-1]);
        }
    }
}

string get_end_date(string date, vector<string> terms){
    string ans = date;
    string term = date[-1];
    int term_month = get_term_date(terms, term);
    
    string month = date.substr(5,2);
    int i_month = stoi(month) + term_month;
    
    if(i_month > 12){
        
    }else{
        string mon = to_string(i_month);
        // date[5]
    }
    
    
} 

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    //파기해야할 번호를 찾으면 된다.
    
    for(int i = 0; i < privacies.size(); i++){
        string date = privacies[i];
        string end_date = get_end_date(date, terms);
        if(is_data_end(end_date, today)){
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}

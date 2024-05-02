#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int get_term_date(vector<string> terms, char term){
    for(auto it : terms){
        if(it[0] == term){
            string tmp = "";
            for(int i = 0; i <it.size(); i++){
                if(it[i] == ' '){
                    tmp = it.substr(i, it.size() - i);
                }
            }
            return stoi(tmp);
        }
    }
    return 0;
}

string get_end_date(string date, vector<string> terms){
    string ans = date;
    char term = date[date.size() - 1];
    int term_month = get_term_date(terms, term);

    string month = date.substr(5,2);
    int i_month = stoi(month) + term_month;

    if(i_month > 12){
        // cout << i_month << endl;
        int i_year = stoi(date.substr(0, 4));
        i_year += i_month / 12;
        
        // cout << year << endl;
        i_month = i_month % 12;
        if(i_month == 0){
            i_year--;
            i_month = 12;
        }
        string year = to_string(i_year);
        // cout << i_month << endl;
        string mon = to_string(i_month);
        
        if(mon.size() == 1){
            mon = "0" + mon;
        }
        
        ans[0] = year[0];
        ans[1] = year[1];
        ans[2] = year[2];
        ans[3] = year[3];
        
        ans[5] = mon[0];
        ans[6] = mon[1];
        
    }else{
        string mon = to_string(i_month);
        if(mon.size() == 1){
            mon = "0" + mon;
        }
        ans[5] = mon[0];
        ans[6] = mon[1];
    }
    return ans.substr(0, 10);
} 

bool is_data_end(string end_date, string today){
    // cout << end_date << ' ' << today << endl;
//     for(int i = 0; i < end_date.size(); i++){
//         char e = end_date[i];
//         char t = today[i];
        
//         if(e == t || e == '.')
//             continue;
        
//         return e < t;
//     }
//     return true;
    return (end_date <= today);
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

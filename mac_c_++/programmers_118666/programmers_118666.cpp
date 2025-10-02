#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> score;
    for(int i = 0; i < survey.size(); i++) {
        char type1 = survey[i][0];
        char type2 = survey[i][1];
        int score_num = choices[i];
        
        switch(score_num) {
            case 1:
                score[type1] += 3;
                break;
            case 2:
                score[type1] += 2;
                break;
            case 3:
                score[type1] += 1;
                break;
            case 5:
                score[type2] += 1;
                break;
            case 6:
                score[type2] += 2;
                break;
            case 7:
                score[type2] += 3;
                break;
        }
    }
    
    if(score['R'] >= score['T']) {
        answer += "R";
    }else {
        answer += "T";
    }
    
    if(score['C'] >= score['F']) {
        answer += "C";
    }else {
        answer += "F";
    }
    
        if(score['J'] >= score['M']) {
        answer += "J";
    }else {
        answer += "M";
    }
    
        if(score['A'] >= score['N']) {
        answer += "A";
    }else {
        answer += "N";
    }
    
    
    return answer;
}
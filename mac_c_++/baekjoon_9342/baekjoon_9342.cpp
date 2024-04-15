#include <iostream>
#include <regex>
#include <vector>

using namespace std;

bool isMatched(string str){
    int index = 1;
    string str_list = "ABCDEF";
    string str_order = "AFC";
    int count_a = 0;
    int count_f = 0;
    int count_c = 0;

    // if(str_list.find(str[index]) != string::npos){
    //     index++;
    // }

    if(str[0] == 'A')
        count_a++;

    for(int i = 1; i < str.size(); i++){

        if(i == str.size() - 1){
            if(count_c == 0){
                if(str[i] == 'C'){
                    return true;
                }else{
                    return false;
                }
            }
            else{
                return str_list.find(str[i]) != string::npos;
            }
        }else{

        if(str[i] == 'A'){
            count_a++;
        }else if(str[i] == 'F'){
            if(count_a == 0){
                return false;
            }else{
                count_f++;
            }
        }else if(str[i] == 'C'){
            if(count_a == 0 || count_f == 0){
                return false;
            }else{
                count_c++;
            }
        }else
            return false;

        }
        
    }
}

int main(void){
    int T;
    regex e("[A, B, C, D, E, F]?A+F+C+[A, B, C, D, E, F]?");

    cin >> T;

    for(int t = 0; t < T; t++){

        string str;
        cin >> str;

        if(isMatched(str)){
            cout << "Infected!" << endl;
        }else{
            cout << "Good" << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <regex>

using namespace std;

int main(void){
    int T;
    regex e("[A, B, C, D, E, F]?A+F+C+[A, B, C, D, E, F]?");

    cin >> T;

    for(int t = 0; t < T; t++){

        string str;
        cin >> str;

        if(regex_match(str, e)){
            cout << "Infected!" << endl;
        }else{
            cout << "Good" << endl;
        }
    }

    return 0;
}
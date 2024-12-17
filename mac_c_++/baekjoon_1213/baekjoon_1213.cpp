#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int indexes[55] = {0};
bool visited[55] = {0};

string name = "";
string ans = "";

bool is_pal(string str){
    for(int i = 0; i <= name.size() / 2; i++){

        if(str[i] != str[name.size() - 1 - i]){
            return false;
        }

    }

    return true;
}

void get_ans(int index){

    if(ans != ""){
        return;
    }

    if(index == name.size()){

        string tmp = "";

        for(int i = 0; i < name.size(); i++){
            tmp += name[indexes[i]];
        }

        if(is_pal(tmp)){
            ans = tmp;
        }

    }else{
        for(int i = 0; i < name.size(); i++){
            if(!visited[i]){
                indexes[i] = index;
                visited[i] = true;

                get_ans(index + 1);

                visited[i] = false;
            }
            
        }
    }
    
}

int main(void){

    cin >> name;

    sort(name.begin(), name.end());

    get_ans(0);

    if(ans == ""){
        cout << "I'm Sorry Hansoo";
    }else{
        cout << ans;
    }

    

    return 0;


    
}
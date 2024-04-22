#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> get_arr(string s){
    vector<string> arr;
    string tmp = "";
    for(auto it : s){
        if(('a' <= it && it <= 'z') || ('A' <= it && it <= 'Z')){
            arr.push_back(tmp);
            tmp = "";
            arr.push_back(it + "");
        }else{
            tmp += it;
        }
    }

    if(tmp != "")
        arr.push_back(tmp);
    return arr;
}

bool compare(string s1, string s2){
    //s1이 s2보다 작으면 true
    vector<string> s1_arr = get_arr(s1);
    vector<string> s2_arr = get_arr(s2);

    int size = min(s1_arr.size(), s2_arr.size());

    for(int i = 0; i < size; i++){
        if(s1_arr[i] != s2_arr[i]){
            return s1_arr[i] < s2_arr[i];
        }
    }
}

int main(void){
    int N;
    vector<string> str;

    cin >> N;

    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        str.push_back(tmp);
    }

    sort(str.begin(), str.end(), compare);

    for(auto it : str){
        cout << it << '\n';
    }

    cout << ("Fo" < "Foo");

    return 0;

}
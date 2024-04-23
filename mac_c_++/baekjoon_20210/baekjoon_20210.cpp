#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string table = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

vector<string> get_arr(string s){
    vector<string> arr;
    string tmp = "";
    for(auto it : s){
        if(('a' <= it && it <= 'z') || ('A' <= it && it <= 'Z')){
            if(tmp != ""){
                arr.push_back(tmp);
                tmp = "";
            }
            // cout << it + "" << endl;
            string c_to_i;
            c_to_i = it;
            arr.push_back(c_to_i);
        }else{
            tmp += it;
        }
    }

    if(tmp != "")
        arr.push_back(tmp);
    return arr;
}

bool is_alpha(string s1){
    return ('a' <= s1[0] && s1[0] <= 'z') || ('A' <= s1[0] && s1[0] <= 'Z');
}

int count_zero(string s){
    int count = 0;
    for(auto it : s){
        if(it != '0')
            break;
        count++;
    }
    return count;
}

string get_no_zero(string s){
    string result = "";
    int index = 0;
    while(s[index] == '0'){
        index++;
    }
    for(int i = index; i < s.size(); i++){
        result += s[i];
    }
    return result;
}

bool get_str_result(string s1, string s2){
    if(s1.size() != s2.size()){
        return s1.size() < s2.size();
    }
    int size = s1.size();
    for(int i = 0; i  < size; i++){
        if(s1[i] != s2[i])
            return s1[i] < s2[i];
    }
}

bool get_comp(string s1, string s2){

    // cout << s1 << ' ' << s2 << endl;

    bool s1_result = is_alpha(s1);
    bool s2_result = is_alpha(s2);

    if(s1_result && s2_result){
        int s1_index = table.find(s1[0]);
        int s2_index = table.find(s2[0]);
        return s1_index < s2_index;
    }
        
    else if(s1_result)
        return false;
    else if(s2_result)
        return true;

    string s1_no_zero = get_no_zero(s1);
    string s2_no_zero = get_no_zero(s2);

    // cout << s1 << ' ' << s2 << ' ' << s1_no_zero << ' ' << s2_no_zero << endl;

    if(s1_no_zero != s2_no_zero){
        // cout << (s1 < s2) << endl;
        return get_str_result(s1_no_zero, s2_no_zero);
    }
    else{
        int s1_count = count_zero(s1);
        int s2_count = count_zero(s2);
    //     // cout << 
        return s1_count < s2_count;
    }

    // long long s1_long = stoll(s1);
    // long long s2_long = stoll(s2);



    // if(s1_long == s2_long){
    //     int s1_count = count_zero(s1);
    //     int s2_count = count_zero(s2);
    //     // cout << 
    //     return s1_count < s2_count;
    // }else{
    //     // cout << s1_long << ' ' << s2_long << (s1_long < s2_long) << endl;
    //     return s1_long < s2_long;
    // }
}

bool compare(string s1, string s2){
    //s1이 s2보다 작으면 true
    vector<string> s1_arr = get_arr(s1);
    vector<string> s2_arr = get_arr(s2);

    int size = min(s1_arr.size(), s2_arr.size());

    for(int i = 0; i < size; i++){
        if(s1_arr[i] != s2_arr[i]){
            // cout << s1_arr[i] << ' ' << s2_arr[i] << endl << endl << (s1_arr[i] < s2_arr[i]) << endl << typeid(s1_arr[i]).name();
            bool comp_result = get_comp(s1_arr[i] ,s2_arr[i]);
            return comp_result;
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

    // string a = "1";
    // string b = "00012";

    // cout << (a > b) << endl;
    // cout << typeid(b).name() << endl << endl;

    // vector<string> tmp = get_arr("Foo00012Bar");

    // for(auto it : tmp){
    //     cout << it << ' ';
    // }

    // tmp = get_arr("Foo1Bar");

    // for(auto it : tmp){
    //     cout << it << ' ';
    // }

    // cout << endl << compare("Foo12Bar", "Foo3Bar");

    return 0;

}
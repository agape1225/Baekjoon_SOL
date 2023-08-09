#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

using namespace std;

string get_lower(string str) {
    string tmp = "";
    for (auto it : str) {
        if ('A' <= it && it <= 'Z') {
            tmp += (it + ('a' - 'A'));
        }
        else {
            tmp += it;
        }
    }
    return tmp;
}

vector<string> get_nums(string str) {
    int index = 0;
    int start = 0;
    vector<string> result;

    for (int i = 0; i < str.size(); i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            index = i;
            break;
        }
    }

    result.push_back(get_lower(str.substr(0, index)));
    start = index;

    for (index = start; index < 5 + start; index++) {
        if (!('0' <= str[index] && str[index] <= '9')) {
            break;
        }
    }
    result.push_back(str.substr(start, index - start));
    result.push_back(str.substr(index, str.size() - index));

    return result;
}

bool compare(string str1, string str2) {
    vector<string> str1_list = get_nums(str1);
    vector<string> str2_list = get_nums(str2);

    cout << "--------------" << endl;
    cout << "str1_list: " << str1_list[0] << ' ' << str1_list[1] << ' ' << str1_list[2] << endl;
    cout << "str2_list: " << str2_list[0] << ' ' << str2_list[1] << ' ' << str2_list[2] << endl;
    cout << "--------------" << endl;

    if (str1_list[0] == str2_list[0]) {
        if (stoi(str1_list[1]) == stoi(str2_list[1])) {
            cout << str1 << ' ' << str2 << endl;
            return false;
        }
        else {
            return stoi(str1_list[1]) < stoi(str2_list[1]);
        }
    }
    else
        return str1_list[0] < str2_list[0];
}

int main(void) {
    vector<string> tmp = get_nums("F-15666666");
    /*vector<string> buff = {
        "9" 10 < 0011 < 012 < 13 < 014
    }*/
    vector<string> tmp_arr = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
    
    sort(tmp_arr.begin(), tmp_arr.end(), compare);

    for (auto it : tmp_arr) {
        cout << it << ' ';
    }

    return 0;
    
    /*for (auto it : tmp) {
        if (it.empty())
            cout << "empty";
        else
            cout << it << endl;
    }*/
    return 0;
}
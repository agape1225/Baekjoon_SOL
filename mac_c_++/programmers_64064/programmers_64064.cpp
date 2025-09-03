#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

set<string> answered_list;
vector<int> lists[10];
int index_list[10] = {0};
bool visited[10] = {0};

void create_set(int index, int size, vector<string> user_id) {
    if(index >= size) {
        vector<string> tmp;
        for(int i = 0; i < size; i++) {
            tmp.push_back(user_id[lists[i][index_list[i]]]);
        }
        sort(tmp.begin(), tmp.end());
        string tmp_str;
        for(auto it : tmp) {
            tmp_str += it;
        }
        // cout << tmp_str << endl << endl;
        
        answered_list.insert(tmp_str);
    }   
    
    for(int i = 0; i < lists[index].size(); i++){
        if(!visited[lists[index][i]]) {
            visited[lists[index][i]] = true;
            index_list[index] = i;
            create_set(index + 1, size, user_id);
            visited[lists[index][i]] = false;
        }
        
    }
}

bool is_comp(string banned_id, string id) {
    if(banned_id.size() != id.size()) {
        return false;
    }
    
    for(int i = 0; i < banned_id.size(); i++) {
        if(banned_id[i] == '*') {
            continue;
        }
        
        if(banned_id[i] != id[i]) {
            return false;
        }
    }
    
    return true;
}

vector<int> get_list(string banned_id, vector<string> user_id) {
    vector<int> arr;
    for(int i = 0; i < user_id.size(); i++) {
        if(is_comp(banned_id, user_id[i])) {
            arr.push_back(i);
        }
    }
    return arr;
}




int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    for(int i = 0; i < banned_id.size(); i++) {
        lists[i] = get_list(banned_id[i], user_id);
        // for(auto it : lists[i]) {
        //     cout << it << ' ';
        // }
        // cout << endl;
    }
    
    create_set( 0, banned_id.size(), user_id);
    
    return answered_list.size();
}
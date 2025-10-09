#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    set<string> s;
    map<string, int> report_count;
    map<string, vector<string>> report_list;
    map<string, int> index_list;
    
    for(int i = 0; i < id_list.size(); i++){
        index_list[id_list[i]] = i;
    }
    
    for(auto it : report) {
        s.insert(it);
    }
    
    for(auto it : s) {
        string repoter = it.substr(0, it.find(' '));
        string repotered = it.substr(it.find(' ') + 1, it.size());
        
        report_count[repotered]++;
        report_list[repotered].push_back(repoter);
    }
    
    for(int i = 0; i < id_list.size(); i++) {
        if(report_count[id_list[i]] >= k) {
            for(auto it : report_list[id_list[i]]) {
                int index = index_list[it];
                answer[index]++;
            }
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

bool comp2(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first) {
        return p1.second < p2.second;    
    }
    return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> catetory_counts;
    map<
        string,
        vector<pair<int, int>>
        > song_dict;
    
    for(int i = 0; i < genres.size(); i++) {
        catetory_counts[genres[i]] += plays[i];
        song_dict[genres[i]].push_back(make_pair(plays[i], i));
    }
    
    vector<pair<string, int>> sorted_dict(
        catetory_counts.begin(), catetory_counts.end()
    );
    
    sort(sorted_dict.begin(), sorted_dict.end(), comp);
    
    for(auto it : sorted_dict) {
        sort(
            song_dict[it.first].begin(), 
            song_dict[it.first].end(), 
            comp2
        );
        int count = 0;
        for(auto tt: song_dict[it.first]) {
            if(count == 2) {
                break;
            }
            answer.push_back(tt.second);
            count++;
        }   
    }
    
    
    return answer;
}
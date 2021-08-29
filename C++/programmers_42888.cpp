#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

struct compare {
    bool operator()(const pair<string, string>& value,
        const string& key)
    {
        return (value.first < key);
    }
    bool operator()(const string& key,
        const pair<string, string>& value)
    {
        return (key < value.first);
    }
};

int get_name_index(vector<pair<string, string>> table, string uid) {

    int left = 0;
    int right = table.size() - 1;
    int mid;
    int ans = -1;

    while (left <= right) {

        mid = (left + right) / 2;

        if (table[mid].first == uid) {
            ans = mid;
            break;
        }

        if(table[mid].first > uid)
            right = mid - 1;
        
        else
            left = mid + 1;
         
    }

    return ans;

}

vector<string> solution(vector<string> record) {

    vector<string> answer;
    vector<pair<string, string>> buff;
    //vector<pair<string, string>> table;
    map<string, string> table;

    for (auto it = record.begin(); it != record.end(); it++) {

        vector<string> tmp;

        stringstream ss;
        string get_str;

        ss.str((*it));

        while (ss >> get_str)
            tmp.push_back(get_str);

        if ((*it)[0] == 'E') {



            buff.push_back(make_pair(tmp[0], tmp[1]));

            // is name exist fix

            auto it = table.find(tmp[1]);

            if (it != table.end()) {

                (*it).second = tmp[2];

            }
            else {

                table.insert(make_pair(tmp[1], tmp[2]));

            }

            // is name doesnt exist push

        }
        else if ((*it)[0] == 'L') {

            buff.push_back(make_pair(tmp[0], tmp[1]));

        }
        else {

            // fix name table

            table[tmp[1]] = tmp[2];

        }

    }

    for (auto it = buff.begin(); it != buff.end(); it++) {

        string name = table[(*it).second];


        if (((*it).first)[0] == 'E') {

            answer.push_back(name + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        }

        else {
            answer.push_back(name + "´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        }


    }

    return answer;
}
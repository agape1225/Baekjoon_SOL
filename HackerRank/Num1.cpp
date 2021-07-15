#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);


// Complete the maxTickets function below.
int maxTickets(vector<int> tickets) {

    //vector<int> buff;

    int count = 1;
    int max = count;

    sort(tickets.begin(), tickets.end());

    int standard = tickets[0];

    for (int i = 1; i < tickets.size(); i++) {

        int tmp = tickets[i] - standard;

        if (tmp == 1 || tmp == 0) {
            count++;

        }
        else {
            if (max < count) {
                max = count;
            }
            count = 1;

        }

        standard = tickets[i];

    }

    return max;


}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string tickets_count_temp;
    getline(cin, tickets_count_temp);

    int tickets_count = stoi(ltrim(rtrim(tickets_count_temp)));

    vector<int> tickets(tickets_count);

    for (int i = 0; i < tickets_count; i++) {
        string tickets_item_temp;
        getline(cin, tickets_item_temp);

        int tickets_item = stoi(ltrim(rtrim(tickets_item_temp)));

        tickets[i] = tickets_item;
    }

    int res = maxTickets(tickets);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

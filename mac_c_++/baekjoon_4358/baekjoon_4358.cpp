#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> m;
    float count = 0;
    string str;

    while (getline(cin, str))
    {
        count++;
        // 없다
        if (m.find(str) == m.end())
            m.insert(make_pair(str, 1));
        else
            m[str]++;
    }

    cout << fixed;
	cout.precision(4);

    for(auto it : m){
        float rate = (it.second / count) * 100;
        cout << it.first << ' ' << rate << '\n';
    }

    return 0;
}
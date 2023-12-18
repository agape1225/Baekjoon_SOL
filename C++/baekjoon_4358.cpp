#include <iostream>
#include <map>
#include <cstdio>
#include <string>
using namespace std;

map<string, int> m;

int main(void) {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	float cnt = 0;

	while (getline(cin, str)) {
		cnt++;
		//¾ø´Ù
		if (m.find(str) == m.end())
			m.insert(make_pair(str, 1));
		else
			m[str]++;
	}
	

	/*for (auto it : m) {

		cout << it.first << ' ' << it.second << endl;
	}*/

	cout << fixed;
	cout.precision(4);

	for (auto it : m) {
		float rate = (it.second / cnt) * 100;
		cout << it.first << ' ' << rate << '\n';
 	}

	return 0;

}
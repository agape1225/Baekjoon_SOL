#include <iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
string s, e, q;
int STT(string s) {
	int h = stoi(s.substr(0, 2));
	int m = stoi(s.substr(3, 2));
	int time = h * 100 + m;
	return time;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> s >> e >> q;

	int s_time = STT(s);
	int e_time = STT(e);
	int q_time = STT(q);

	set<string> us;
	set<string> uscnt;

	while (1) {
		string s1, s2;
		cin >> s1 >> s2;

		if (s1 == "" && s2 == "") break;

		int s1_time = STT(s1);

		if (s1_time <= s_time) {
			us.insert(s2);
		}
		else if (s1_time >= e_time && s1_time <= q_time) {
			if (us.find(s2) != us.end())
				uscnt.insert(s2);
		}
	}
	cout << uscnt.size() << '\n';
}
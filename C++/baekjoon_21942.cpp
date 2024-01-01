#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

int get_diff(string start, string end) {

	int mon = (stoi(end.substr(5, 2)) - stoi(start.substr(5, 2))) * 60 * 24 * 30;
	int day = (stoi(end.substr(8, 2)) - stoi(start.substr(8, 2))) * 60 * 24;
	int hour = (stoi(end.substr(11, 2)) - stoi(start.substr(11, 2))) * 60;
	int min = (stoi(end.substr(14, 2)) - stoi(start.substr(14, 2)));
	cout << mon << ' ' << day << ' ' << hour << ' ' << min << endl;
	return mon + day + hour + min;
}

int main(void) {
	int N, F, rental_period;
	string L;
	map<string, int> ans;
	map<pair<string, string>, string> m;

	cin >> N >> L >> F;

	rental_period = 
		(stoi(L.substr(0, 3)) * 24 * 60) + 
		(stoi(L.substr(4,2)) * 60) + 
		stoi(L.substr(7, 2));

	cout << rental_period << endl;

	for (int i = 0; i < N; i++) {
		string date, time, P, M;
		cin >> date >> time >> P >> M;
		auto it = m.find(make_pair(P, M));
		if (it != m.end()) {
			//대여시각
			string start = (*it).second;
			//반납시각
			string end = date + ' ' + time;

			int diff = get_diff(start, end);
			if (rental_period < diff) {
				int final_fin = (diff - rental_period) * F;
				auto is_name_in = ans.find(M);
				if (is_name_in != ans.end()) {
					ans[M] += final_fin;
				}
				else {
					ans.insert(make_pair(M, final_fin));
				}
			}
		}
		else {
			m.insert(make_pair(make_pair(P, M), date + ' ' + time));
		}
	}

	for (auto it : ans) {
		cout << it.first << ' ' << it.second << '\n';
	}

	return 0;

}
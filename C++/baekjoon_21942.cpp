#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

long long get_diff(string start, string end) {

	int end_mon = stoi(end.substr(5, 2));
	int end_mon_tmp = 0;
	int start_mon = stoi(start.substr(5, 2));
	int start_mon_tmp = 0;

	for (int i = 0; i < end_mon -1; i++) {
		end_mon_tmp += days[i];
	}
	for (int i = 0; i < start_mon-1; i++) {
		start_mon_tmp += days[i];
	}

	long long day = ((stoi(end.substr(8, 2)) + end_mon_tmp) - (stoi(start.substr(8, 2)) + start_mon_tmp)) * 60 * 24;
	long long hour = (stoi(end.substr(11, 2)) - stoi(start.substr(11, 2))) * 60;
	long long min = (stoi(end.substr(14, 2)) - stoi(start.substr(14, 2)));
	//cout << mon << ' ' << day << ' ' << hour << ' ' << min << endl;
	return day + hour + min;
}

int main(void) {
	int N, F;
	long long rental_period;
	string L;
	map<string, long long> ans;
	map<pair<string, string>, string> m;

	cin >> N >> L >> F;

	rental_period = 
		(stoi(L.substr(0, 3)) * 24 * 60) + 
		(stoi(L.substr(4,2)) * 60) + 
		stoi(L.substr(7, 2));

	for (int i = 0; i < N; i++) {
		string date, time, P, M;
		cin >> date >> time >> P >> M;
		auto it = m.find(make_pair(P, M));
		if (it != m.end()) {
			string start = (*it).second;
			string end = date + ' ' + time;

			long long diff = get_diff(start, end);
			if (rental_period < diff) {
				long long final_fin = (diff - rental_period) * F;
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
	if (ans.size() == 0)
		cout << -1;
	else {
		for (auto it : ans)
			cout << it.first << ' ' << it.second << '\n';
		
	}
	
	return 0;

}
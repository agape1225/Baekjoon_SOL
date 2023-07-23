#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

long long CCW(
	pair<long long, long long> p1, 
	pair<long long, long long> p2, 
	pair<long long, long long> p3) {
	long long tmp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	tmp -= p2.first * p1.second + p3.first * p2.second + p1.first * p3.second;

	if (tmp > 0) 
		return 1;
	else if (tmp == 0) 
		return 0;
	else if (tmp < 0) 
		return -1;
	
	return 0;
}

int main(void) {

	pair<pair<long long, long long>, pair<long long, long long>> L1;
	pair<pair<long long, long long>, pair<long long, long long>> L2;

	int ans;

	cin >> L1.first.first >> L1.first.second >> L1.second.first >> L1.second.second;
	cin >> L2.first.first >> L2.first.second >> L2.second.first >> L2.second.second;

	long long tmp1 = CCW(L1.first, L1.second, L2.first) * CCW(L1.first, L1.second, L2.second);
	long long tmp2 = CCW(L2.first, L2.second, L1.first) * CCW(L2.first, L2.second, L1.second);

	if (tmp1 == 0 && tmp2 == 0) {
		
		if (L1.first > L1.second)
			swap(L1.first, L1.second);

		if (L2.first > L2.second)
			swap(L2.first, L2.second);
		
		if (L1.first <= L2.second && L1.second >= L2.first)
			ans = 1;
		else
			ans = 0;
	}
	else {
		if (tmp1 <= 0 && tmp2 <= 0)
			ans = 1;
		else
			ans = 0;
	}

	cout << ans;
}
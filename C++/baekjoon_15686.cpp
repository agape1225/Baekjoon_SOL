#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int city[50][50] = { 0 };
int city_size = 0;
int ans = 987654321;

vector<pair<int, int>> stores;
vector<pair<int, int>> houses;

int indexes[13];
int N, M;

int get_min(int row, int col) {
	int ans = 98754310;
	for (int i = 0; i < M; i++) {
		int buff = abs(row - stores[indexes[i]].first) + abs(col - stores[indexes[i]].second);
		ans = min(ans, buff);
	}
	return ans;
}

void comb(int count, int start) {
	if (count < M) {
		for (int i = start; i < city_size; i++) {
			indexes[count] = i;
			comb(count + 1, i + 1);
		}
	}
	else {
		//실행 함수
		
		/*for (int i = 0; i < M; i++) {
			cout << stores[indexes[i]].first << ' ' << stores[indexes[i]].second << endl;
		}
		cout << "-----------" << endl;*/

		int buff = 0;

		for (auto it : houses) {
			buff += get_min(it.first, it.second);
		}

		ans = min(ans, buff);
	}
}

int main(void) {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 2) {
				stores.push_back(make_pair(i, j));
				city_size++;
			}
			else if (city[i][j] == 1) {
				houses.push_back(make_pair(i, j));
			}
		}
	}

	comb(0, 0);

	cout << ans;

	return 0;
}
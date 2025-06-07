#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

//cache[i][j] -> i개의 도시를 탐색했을 때 최소 j까지 발생하는 비용
int cache[25][1005] = {0};
vector<pair<int,int>> cost_info_list;

int main(void) {

	int C, N;
	int cost, number;

	cin >> C >> N;

	for(int i = 0; i < N; i++) {
		cin >> cost >> number;
		cost_info_list.push_back(
			make_pair(cost, number)
		);	
	}

	for(int i = 1; i <= N; i++) {
		cost = cost_info_list[i - 1].first;
		number = cost_info_list[i - 1].second;

		for(int j = 1; j <= C; j++) {
			int real_cost = ceil((j + 0.0) / number) * cost;
			// cout << ceil((j + 0.0)/ number) << endl;
			// cout << real_cost << endl;

			if(i == 1) {
				cache[i][j] = real_cost;
			}else {
				if(number <= j) {
					cache[i][j] = min(cache[i - 1][j], min(cache[i][j - number] + cost, cache[i - 1][j - number] + cost));
				}else {
					cache[i][j] = min(cache[i - 1][j], real_cost);
				}
			}

		}
	}

	// for(int i = 0; i <= N; i++) {
	// 	for(int j = 0; j <= C; j++) {
	// 		cout << cache[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	cout << cache[N][C];

	return 0;

}
#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;


int road[501][501]; // 방향 있음
int hole[501][501];
int ans[501][501];

int main(void) {

	int TC;
	cin >> TC;


	for (int tc = 0; tc < TC; tc++) {

		//init
		int N, M, W;
		int S, E, T;
		cin >> N >> M >> W;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				road[i][j] = INF;
			}
		}

		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			road[S][E] = road[E][S]= min(road[S][E], T);
		}

		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;

			road[S][E] = min(road[S][E], -1 * T);
			//road[E][S] = min(road[E][S], -1 * T);
		}

		/*cout << endl << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << road[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl << endl;*/

		for (int middle = 1; middle <= N; middle++) {

			for (int start = 1; start <= N; start++) {

				for (int end = 1; end <= N; end++) {

					//ans[start][end] = max(ans)
					road[start][end] = min(road[start][end], road[start][middle] + road[middle][end]);

				}

			}
			
		}


		/*cout << endl << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << road[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl << endl;*/

		string ans = "NO";

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j && road[i][j] < 0) {
					ans = "YES";
				}
			}
		}
		cout << ans << endl;
	}

	return 0;

}
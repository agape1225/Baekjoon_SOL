#include <iostream>
#include <vector>
#include <utility>
#define INF 987654321

using namespace std;

int n;
int m;
//vector<pair<int, int>> bus[101];
int graph[101][101] = {0};

int main(void) {

	int buff1, buff2, buff3;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++)
			graph[i][j] = INF;
	}

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> buff1 >> buff2 >> buff3;
		//bus[buff1].push_back(make_pair(buff2, buff3));
		if(graph[buff1][buff2] == INF)
			graph[buff1][buff2] = buff3;
		else {
			if (buff3 < graph[buff1][buff2])
				graph[buff1][buff2] = buff3;
		}
	}

	for (int i = 1; i <= n; i++) {		//i를 거쳐감
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}

		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] >= INF || i == j)
				cout << 0 << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;




}
#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int graph[101][101];

int main(void) {

	int n, m;
	cin >> n >> m;
	int start, end, weight;

	//intializing
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> start >> end >> weight;
		graph[start][end] = min(graph[start][end], weight);
	}

	for (int middle = 1; middle <= n; middle++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {

				if(start != end)
					graph[start][end] = min(graph[start][middle] + graph[middle][end], graph[start][end]);

				/*cout << start << ' ' << middle << ' ' << end << endl;
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) {
						cout << graph[i][j] << ' ';
					}
					cout << endl;
				}
				cout << endl;*/
			}
		}



	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] >= INF)
				cout << 0 << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
#include <iostream>

#define SIZE 20001
#define MAX 11

using namespace std;

int graph[SIZE][SIZE];
bool complet[SIZE] = { 0 };

int V, E;
int start;

int get_index(int v, int start) {

	int min = MAX;
	int ans = -1;

	/*for (int i = 1; i <= v; i++)
		cout << graph[start][i] << ' ';
	cout << endl;*/

	for (int i = 1; i <= v; i++) {

		if (graph[start][i] != 0 && graph[start][i] < min && !complet[i]) {
			min = graph[start][i];
			ans = i;
		}

	}

	return ans;

}

bool is_end(int v, int start) {

	for (int i = 1; i <= v; i++) {

		if (!complet[i] && start != i && graph[start][i] != MAX)
			return false;

	}

	return true;

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	cin >> V >> E;
	cin >> start;

	for (int i = 1; i <= V; i++) {

		for (int j = 1; j <= V; j++) {
			if(i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = MAX;
		}
			

	}

	for (int i = 0; i < E; i++) {
		int buff1, buff2;

		cin >> buff1 >> buff2;
		cin >> graph[buff1][buff2];
	}

	/*for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}*/

	while (true) {

		//cout << 1;

		int index = get_index(V, start);
		complet[index] = true;

		//cout << index << endl;

		for (int i = 1; i <= V; i++) {
			if (graph[index][i] != MAX) {
				if (graph[index][i] + graph[start][index] < graph[start][i]) {
					graph[start][i] = graph[index][i] + graph[start][index];
				}
			}
		}

		if (is_end(V, start))
			break;
	}

	for (int i = 1; i <= V; i++) {
		if (graph[start][i] != MAX)
			cout << graph[start][i] << endl;
		else
			cout << "INF" << endl;
	}

	return 0;

}
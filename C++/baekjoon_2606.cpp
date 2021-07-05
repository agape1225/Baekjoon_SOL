#include <iostream>
#include <vector>
#include <queue>
#define SIZE 100

using namespace std;

int get_point(bool graph[SIZE][SIZE], int start, int node) {

	for (int i = 0; i < node; i++) {

		if (graph[start][i] == true)
			return i;

	}

	return -1;
}

int main(void) {

	queue<int> q;
	bool graph[SIZE][SIZE] = { 0 };
	bool ans[SIZE] = { 0 };
	int node, size;
	int buff1, buff2;
	int start;
	//int ans = 0;

	cin >> node >> size;

	start = 0;

	for (int i = 0; i < size; i++) {

		cin >> buff1 >> buff2;
		buff1--;
		buff2--;

		//cout << buff1 << " " << buff2 << endl;

		graph[buff1][buff2] = true;
		graph[buff2][buff1] = true;

	}

	/*for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			cout << graph[i][j] << " ";

		}

		cout << endl;
	}*/

	while (true) {

		int loc = get_point(graph, start, node);

		//cout << loc << endl;

		//cout << start << ' ' << loc << endl;

		if (loc != -1) {

			//ans++;

			ans[start] = true;
			ans[loc] = true;

			graph[start][loc] = false;
			graph[loc][start] = false;

			q.push(start);
			start = loc;
			//q.push(start);

			//cout << q.size() << endl << endl;
		}
		else if(!q.empty()){

			start = q.front();
			q.pop();
			
		}
		else {

			break;

		}
	}

	int tmp = 0;

	for (int i = 1; i < node; i++) {

		if (ans[i])
			tmp++;

	}

	cout << tmp;

}
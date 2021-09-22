#include <iostream>
#include <vector>
#include <utility>

#define SIZE 100001

using namespace std;

int dp[SIZE];

int main(void) {

	vector<pair<int, int>> bag;
	int N, K;
	int buff1, buff2;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		
		cin >> buff1 >> buff2;
		bag.push_back(make_pair(buff1, buff2));

	}


	for (int i = 1; i < K; i++) {

	}

}
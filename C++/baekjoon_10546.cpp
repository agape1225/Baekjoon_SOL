#include <iostream>
#include <set>

using namespace std;

int main(void) {
	multiset<string> ms;
	string name;
	int N;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> name;
		ms.insert(name);
	}

	for (int i = 0; i < N - 1; i++) {
		cin >> name;
		auto it = ms.find(name);
		ms.erase(it);
	}

	cout << *ms.begin();

	return 0;
}
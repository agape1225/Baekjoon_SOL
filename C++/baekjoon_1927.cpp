#include <set>
#include <iostream>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	multiset<int> ms;

	int size, buff;
	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> buff;

		if (buff == 0) {
			if (ms.empty()) {

				cout << 0 << '\n';

			}else{

				cout << *ms.begin() << '\n';
				ms.erase(ms.begin());

			}
			
		}
		else {
			ms.insert(buff);
		}

	}
}
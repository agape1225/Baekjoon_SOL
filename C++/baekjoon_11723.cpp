#include <iostream>
#include <set>

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> s;
	int size, buff, trash;
	string input;

	cin >> size;

	for (int i = 0; i < size; i++) {

		//cout << i << endl;

		cin >> input;

		if (input == "add") {
			cin >> buff;
			s.insert(buff);
		}
		else if (input == "remove") {

			cin >> buff;
			auto it = s.find(buff);

			if (s.end() != it)
				s.erase(it);

		}
		else if (input == "check") {
			cin >> buff;
			auto it = s.find(buff);

			if (s.end() == it)
				cout << 0 << '\n';
			else
				cout << 1 << '\n';


		}
		else if (input == "toggle") {
			cin >> buff;
			auto it = s.find(buff);

			if (s.end() == it)
				s.insert(buff);
			else
				s.erase(it);

		}
		else if (input == "all") {

			//s.clear();
			set<int> s;

			for (int j = 1; j < 21; j++) {

				s.insert(j);

			}

		}
		else {				// empty

			//s.clear();
			set<int> s;

		}
	}

	return 0;

}
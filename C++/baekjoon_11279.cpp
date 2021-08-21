#include <set>
#include <iostream>
//#include <multiset>

using namespace std;

int main(void) {

	multiset<int> mq;
	
	int N, buff;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> buff;

		if (buff == 0) {
			
			if (mq.empty())
				cout << 0 << endl;
			else {

				auto it = mq.end();
				cout << *(--it) << endl;
				mq.erase(it);
			}
			
		}
		else {
			mq.insert(buff);
		}

	}

	return 0;

}
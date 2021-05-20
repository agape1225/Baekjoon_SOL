#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {

	vector<string> arr1;
	vector<string> arr2;
	vector<string> ans;
	
	string buff;

	int N, M;

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> buff;
		arr1.push_back(buff);
	}

	for (int i = 0; i < M; i++) {
		cin >> buff;
		arr2.push_back(buff);
	}

	sort(arr1.begin(), arr1.end());
	//sort(arr2.begin(), arr2.end());

	//cout << arr2.size() << endl;
	for (int i = 0; i < M; i++) {
		//cin >> buff;
		buff = arr2[i];
		/*auto it = find(arr1.begin(), arr1.end(), buff);
		binary_search(arr1.begin(), arr1.end(), buff);*/

		if (binary_search(arr1.begin(), arr1.end(), buff))
			ans.push_back(buff);

	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

	/*cout << endl;

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}

	sort(arr.begin(), arr.end());
	cout << endl;

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}*/

	return 0;	

}
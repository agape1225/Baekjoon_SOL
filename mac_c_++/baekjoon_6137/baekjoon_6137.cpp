#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    // ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);

    string s = "";
    string t = "";

    int N;

    cin >> N;

    // cout << N;

    for(int i = 0; i < N; i++){
        // cout << "s";
        char tmp;
        cin >> tmp;
        s += tmp;
    }


    int left = 0;
    int right = N - 1;

    while(left <= right) {
        if(s[left] < s[right]){
            t += s[left++];
        }else if(s[left] > s[right]){
            t += s[right--];
        }else {

            bool is_add = false;
            int tmp_left = left +1;
            int tmp_right = right - 1;
            while(tmp_left <= tmp_right) {
                if(s[tmp_left] < s[tmp_right]){
                    t += s[left++];
                    is_add = true;
                    break;
                }else if(s[tmp_left] > s[tmp_right]) {
                    t += s[right--];
                    is_add = true;
                    break;
                }else{
                    tmp_left++;
                    tmp_right--;
                }
            }

            if(!is_add){
                t += s[right--];
            }

        }
    }

	
	for (int i = 0; i < t.size(); i++) {
		if (i != 0 && i % 80 == 0) cout << "\n";
		cout << t[i];
	}
    // cout << t;

    return 0;


}
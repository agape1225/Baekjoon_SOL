#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int N, L;
    vector<int> trees;
    
    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        trees.push_back(tmp);
    }

    sort(trees.begin(), trees.end());

    for(int i = 0; i < trees.size(); i++) {
        if(L >= trees[i]) {
            L++;
        }else {
            break;
        }
    }

    cout << L;
    
    return 0;
}

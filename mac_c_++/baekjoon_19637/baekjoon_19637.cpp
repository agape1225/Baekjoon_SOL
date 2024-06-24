#include <iostream>
#include <vector>
#include <utility>

using namespace std;

auto get_lower_bound(auto left, auto right, auto value){
    auto mid;
    while(left < right){
        mid = (left + right) / 2;

        if(*mid == value)
            return mid;
        else if(mid )
    }
}

int main(void){

    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long N, M;
    // vector<pair<string, int>> styles;
    vector<string> styles;
    vector<long> values;
    string style;
    long value;

    cin >> N >> M;

    for(long i = 0; i < N; i++){
        cin >> style >> value;
        styles.push_back(style);
        values.push_back(value);
    }

    long m;
    for(long i = 0; i < M; i++){
        cin >> m;
        int index = get_lower_bound(values.begin(), values.end(), m) - values.begin();
        cout << styles[index] << '\n';
    }

    return 0;
}
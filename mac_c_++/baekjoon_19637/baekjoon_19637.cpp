    #include <iostream>
    #include <vector>
    #include <utility>

    using namespace std;

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

            // styles.push_back(make_pair(style, value));
        }

        long m;
        for(long i = 0; i < M; i++){
            cin >> m;
            int index = lower_bound(values.begin(), values.end(), m) - values.begin();
            cout << styles[index] << '\n';
        }

        return 0;
    }
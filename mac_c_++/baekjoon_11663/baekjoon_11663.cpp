#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> points;

int get_start_index(int start){
    int left = 0;
    int right = points.size() - 1;
    int ans;

    //작거나 같은애
    while(left <= right){
        int mid = (left + right) / 2;

        // cout << left << ' ' << right << ' ' << mid << endl << endl;
        
        if(points[mid] >= start){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    return left;
}

int get_end_index(int end){
    int left = 0;
    int right = points.size() - 1;

    //작거나 같은애
    while(left <= right){
        int mid = (left + right) / 2;
        if(points[mid] <= end){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return left;
}

int main(void){
    int N, M, point, start, end;
    
    vector<pair<int, int>> lines;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> point;
        points.push_back(point);
    }

    for(int i = 0; i < M; i++){
        cin >> start >> end;
        lines.push_back(make_pair(start, end));
    }

    sort(points.begin(), points.end());

    for(auto pos : lines){
        int start = pos.first;
        int end = pos.second;

        int start_index = get_start_index(start);
        int end_index = get_end_index(end);
        // cout << start_index << ' ' << end_index << endl;
        cout << end_index - start_index << '\n';
    }

    return 0;


}

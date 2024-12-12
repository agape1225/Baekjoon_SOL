#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;


    int cache[100005] = {0};

int get_parent(int node){
    if(cache[node] == node){
        return node;
    }return cache[node] = get_parent(cache[node]);
}

void union_parent(int node1, int node2){
    int root1 = get_parent(node1);
    int root2 = get_parent(node2);

    if(root1 < root2){
        cache[root2] = root1;
    }else{
        cache[root1] = root2;
    }
}

bool find(int node1, int node2){
    int root1 = get_parent(node1);
    int root2 = get_parent(node2);

    // cout << node1 << ' ' << node2 << ' ' << root1 << ' ' << root2 << endl;

    return root1 == root2;
}

bool comp(pair<int, pair<int, int>> node1, pair<int, pair<int, int>> node2){
    if(node1.first != node2.first){
        return node1.first < node2.first;
    }else{
        if(node1.second.first != node2.second.first){
            return node1.second.first < node2.second.first;
        }
        else{
            return node1.second.second < node2.second.second;
        }
    }
}

int main(void){
    
    vector<pair<int,pair<int, int>>> arr;
    int V, E;
    int from, to, weight;
    long long ans = 0;

    cin >> V >> E;

    // 간선 리스트 생성
    for(int i  = 0; i < E; i++){
        cin >> from >> to >> weight;
        arr.push_back(
            make_pair(weight, make_pair(from, to))
        );
    }
    sort(arr.begin(), arr.end(), comp);

    // union find 배열 생성
    for(int i = 1; i <= V; i++){
        cache[i] = i;
    }

    for(auto it : arr){

        // cout << it.second.first << ' ' <<  it.second.second << ' ' << it.first << endl;

        // find( it.second.first, it.second.second);
        // union_parent(it.second.first, it.second.second);
        if(!find( it.second.first, it.second.second) ) {
            // cout << it.first << endl;
            ans += it.first;
            union_parent(it.second.first, it.second.second);
        }
    }

    cout << ans;
    
    return 0;


}
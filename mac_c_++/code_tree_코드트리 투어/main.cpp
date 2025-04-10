#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
using namespace std;

#define INIT 100
#define CREATE 200
#define DELETE 300
#define READ 400
#define UPDATE 500
#define INF 987654321

int N, M, Q;
int COMMAND;


vector<pair<int, int>> graph[2005];
priority_queue<pair<int, int>> product_dic;
int cache[2005] = {0};
map<int, pair<int, int>> product;

int start_node = 0;

void set_cache() {

    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < N; i++) {
        cache[i] = INF;
    }

    cache[start_node] = 0;
    pq.push(make_pair(0, start_node));

    while(!pq.empty()) {
        int weight = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : graph[node]) {
            int next_node = it.first;
            int next_weight = it.second + weight;

            if(cache[next_node] > next_weight) {
                cache[next_node] = next_weight;
                pq.push(make_pair(-next_weight, next_node));
            }
        }
    }
    // int pay_back = -1;
    // int id = -1;
    // for(auto it : product) {
    //     int tmp = it.second.first - cache[it.second.second];
    //     if(tmp > -1 && pay_back < tmp) {
    //         id = it.first;
    //         pay_back = tmp;
    //     }
    // }
    
    // return id;
}

void update_product_dict() {

    while(product_dic.size() > 0) {
        product_dic.pop();
    }

    for(auto it : product) {
        int tmp = it.second.first - cache[it.second.second];
        if(tmp > -1) {
            product_dic.push(make_pair(tmp, -it.first));
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Please write your code here.
    cin >> Q;
    cin >> COMMAND >> N >> M;

    

    // for(int i = 0; i < N; i++) {
    //     cout << cache[i] << ' ';
    // }
    // cout << endl;

    for(int i = 0; i < M; i++) {
        int v, u, w;
        cin >> v >> u >> w;

        // cout << v << ' ' << u << ' ' << w << endl; 

        graph[v].push_back(make_pair(u, w));
        graph[u].push_back(make_pair(v, w));
    }

    set_cache();

    for(int q = 0; q < Q - 1; q++) {
        cin >> COMMAND;
        // cout << COMMAND << endl;
        if(COMMAND == CREATE) {
            int id, revenue, dest;
            cin >> id >> revenue >> dest;
            

            int tmp = revenue - cache[dest];
            // cout << tmp << endl;
            product.insert(make_pair(id, make_pair(revenue, dest)));
            if(tmp > -1) {
                product_dic.push(make_pair(tmp, -id));
            }

        }else if(COMMAND == DELETE) {
            int id;
            cin >> id;
            product.erase(id);
        }else if(COMMAND == READ) {
            // sell
            int ans_id = -1;
            while(product_dic.size() > 0) {
                int id = -product_dic.top().second;
                product_dic.pop();

                if(product.find(id) != product.end()) {
                    ans_id = id;
                    product.erase(id);
                    break;
                }
            }

            cout << ans_id << '\n';

        }else if(COMMAND == UPDATE) {
            int s;
            cin >> s;
            start_node = s; 

            set_cache();
            //update product dic
            update_product_dict();
        }
    }



    return 0;
}
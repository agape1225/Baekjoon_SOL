#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>

using namespace std;

// 비용 배열
int cost[15][15] = {0};

// vector<int>를 사용하는 자료구조
vector<int> arr;
map<vector<int>, long long> m;
// 우선순위 큐는 min-heap으로 동작하도록 greater<> 사용
priority_queue<pair<long long, vector<int>>, vector<pair<long long, vector<int>>>, greater<pair<long long, vector<int>>>> q;

int N, M;
int l, r, c;
long long ans = -1;

// --- create_set 메소드 (vector<int> 버전) ---
vector<int> printed_vecs;
bool printed_chars_visited[15] = {0};

void create_set(int index) {
    if (index == N) {
        // 완성된 순열을 map에 삽입
        m.insert({printed_vecs, 9876543210LL});
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!printed_chars_visited[i]) {
            printed_chars_visited[i] = true;
            printed_vecs[index] = arr[i];
            create_set(index + 1);
            printed_chars_visited[i] = false;
        }
    }
}
// --- create_set 종료 ---


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    // 입력을 vector<int>로 받음
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // create_set에서 사용할 vector 크기 설정
    printed_vecs.resize(N);

    // 비용 배열 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cost[i][j] = -1;
        }
    }

    cin >> M;

    // 양방향으로 비용 저장
    for (int i = 0; i < M; i++) {
        cin >> l >> r >> c;
        if (cost[l - 1][r - 1] == -1 || c < cost[l - 1][r - 1]) {
             cost[l - 1][r - 1] = c;
             cost[r - 1][l - 1] = c;
        }
    }

    // set 생성
    create_set(0);

    // 시작 상태 초기화
    // m.find()는 iterator를 반환하므로, [] 연산자로 접근하는 것이 더 간편함
    m[arr] = 0;
    q.push({0, arr});
    
    // 목표 상태(정렬된 벡터) 생성
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());

    while (!q.empty()) {
        long long current_count = q.top().first;
        vector<int> current_vec = q.top().second;
        q.pop();

        if (current_count > m[current_vec]) {
            continue;
        }

        // if (current_vec == sorted_arr) {
        //     // 목표를 찾았으므로 루프 종료
        //     break;
        // }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (cost[i][j] != -1) {
                    vector<int> tmp_vec = current_vec;
                    swap(tmp_vec[i], tmp_vec[j]);
                    
                    long long new_cost = current_count + cost[i][j];

                    // map에 키가 없거나(create_set으로 미리 생성했으므로 항상 존재),
                    // 더 작은 비용을 발견하면 갱신
                    if (m[tmp_vec] > new_cost) {
                        m[tmp_vec] = new_cost;
                        q.push({new_cost, tmp_vec});
                    }
                }
            }
        }
    }
    
    ans = m[sorted_arr];

    if (ans == 9876543210LL) {
        cout << -1;
    } else {
        cout << ans;
    }
    
    return 0;
}
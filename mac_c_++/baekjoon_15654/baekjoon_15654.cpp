#include <iostream>
#include <algorithm>

using namespace std;

vector<int> arr;
int print_buffer[10] = {0};
bool visited[10] = {0};

void print_arr(int count, int N, int M) {
    if(M == count) {
        for(int i = 0; i < count; i++) {
            cout << print_buffer[i] << ' ';
        }
        cout << endl;
    }else {
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                visited[i] = true;
                print_buffer[count] = arr[i];
                print_arr(count + 1, N, M);
                visited[i] = false;
            }
        }
    }
}

int main(void) {
    int N, M;
    // int arr[10] = {0};
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    print_arr(0, N, M);

    return 0;
}
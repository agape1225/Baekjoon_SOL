#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main(void){
    multiset<int> ms;
    int N, input, mid;
    auto ans_index = ms.begin();
    priority_queue<int> max_q;
    priority_queue<int> min_q;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> input;

        if(i == 0){
            // mid = input;
            max_q.push(input);
        }else{

            int mid = max_q.top();

            if(mid < input){
                min_q.push(-input);

            }else{
                max_q.push(input);
            }

            if(max_q.size() <= min_q.size()){
                
            }

        }
        cout << max_q.top() << '\n';
    }

    return 0;
}
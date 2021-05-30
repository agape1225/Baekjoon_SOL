#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> ans;
    stack<int> a;

    int max;
    int dir = true;
    int count = 0;

    for (int i = 0; i < progresses.size(); i++) {

        int buff = 100 - progresses[i];
        int ans = buff / speeds[i];

        if (buff % speeds[i] > 0)
            ans++;

       progresses[i] = ans;

       cout << progresses[i] << " ";

    }

    

    for (int i = 0; i < progresses.size() - 1; i++) {

        ans.push(progresses[i]);

        if (dir) {
            max = progresses[i];
            dir = false;
        }
            

        if (max < progresses[i + 1]) {
            
            answer.push_back( ans.size());
            //count++;
            while (!(ans.empty()))
                ans.pop();
        }

    }
    ans.push(progresses[progresses.size() - 1]);
    answer.push_back(ans.size());

    //for (int i = 0; i < answer.size(); i++)
    //    a.push(answer[i]);
    //for (int i = 0; i < answer.size(); i++)
    //{
    //    answer[i] = a.top();
    //    a.pop();
    //}

    //answer[count] = ans.size();

    return answer;
}

int main(void) {
    vector<int> pro = { 95, 90, 99, 99, 80, 99 };
    vector<int> spe = { 1, 1, 1, 1, 1, 1 };

    vector<int> ans = solution(pro, spe);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> order = {'w', 'o', 'l', 'f'};

int get_N(int start_num, string s){
    int count = 0;
    for(int i = start_num; i < s.size(); i++){
        if(s[i] == 'w'){
            return count;
        }else{
            
            count++;
        }
    }
    return -1;
}

int get_end(int start, int N, string s){
    for(int i = start + N; i < s.size(); i++){
        if(i == 'w')
            return i - 1;
    }
    return s.size();
}

bool is_wolf_num(int start, int end, string s, int N){
    int index = 0;
    int tmp_end = start + N;
    for(int i = start; i < end; i++){
        if(i == tmp_end){
            index++;
            tmp_end = tmp_end + N;
        }

        // cout << i << ' ' << index << endl;

        if(s[i] != order[index]){
            return false;
        }
    }
    return true;
}

int is_ans(string s){
    int start_num = 0;
    for(int i = 0; i < s.size(); i++){
        int N = get_N(i, s);
        // cout << N << endl;
        int start = i;
        int end = get_end(start, N, s);

        cout << start << ' ' << end << endl;

        if(!is_wolf_num(start, end, s, N)){
            return 0;
        }

        i = i + end;
    }
    return 1;
}

int main(void){
    string s;
    int ans;
    cin >> s;

    ans = is_ans(s);
    cout << ans;
    return ans;
}
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

    int k;
    int n;
    string board[1005];
    string ans;
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string target;
    int blank_index = 0;

int get_index(char alpha){

    for(int i = 0; i < alphabets.size(); i++){
        if(alphabets[i] == alpha)
            return i;
    }

}

int get_end_index(char alpha){

    for(int i = 0; i < target.size(); i++){
        if(target[i] == alpha)
            return i;
    }

}

int get_start_pos(char alpha){

    int index = get_index(alpha);
    // cout << index << endl;

    for(int i = 0; i < n; i++){

        if(i == blank_index)
            break;

        int next_index = index;
        // cout << board[i][index] << endl;
        if(index == 0){
            if(board[i][index] == '-'){
                next_index++;
            }
        }

        else if(index == k - 1){
            if(board[i][index - 1] == '-'){
                next_index--;
            }
        } else {
            if(board[i][index] == '-'){
                next_index++;
            }else if(board[i][index - 1] == '-'){
                next_index--;
            }
        }

        index = next_index;
    }

    return index;
}

// -*-******

int get_end_pos(char alpha){

    int index = get_end_index(alpha);

    // cout << index << endl;

    for(int i = n - 1; i >= 0; i--){

        if(i == blank_index)
            break;

        // cout << board[i][index] << endl;

        int next_index = index;
        if(index == 0){
            if(board[i][index] == '-'){
                next_index++;
            }
        }

        else if(index == k - 1){
            if(board[i][index - 1] == '-'){
                next_index--;
            }
        } else {
            if(board[i][index] == '-'){
                next_index++;
            }else if(board[i][index - 1] == '-'){
                next_index--;
            }
        }

        index = next_index;
    }

    return index;
}

int main(void){

    cin >> k >> n;
    cin >> target;

    for(int i = 0; i < n; i++){
        cin >> board[i];
        if(board[i][0] == '?'){
            ans = board[i];
            blank_index = i;
        }
            
    }

    for(int i = 0; i < k; i++){
        char alphabet = alphabets[i];
        int start_pos = get_start_pos(alphabet);
        int end_pos = get_end_pos(alphabet);

        // cout << start_pos << ' ' << end_pos << endl;

        if(abs(start_pos - end_pos) > 1){
            //end
            ans = "";
            for(int j = 0; j < k - 1; j++){
                ans += 'x';
            }
            break;
        }

        if(start_pos == end_pos){
            //양 옆이 비어있어야함
            if(start_pos == 0){
                ans[start_pos] = '*';
                
            }else if(start_pos == k){
                
                ans[start_pos - 1] = '*';

            }else{
                ans[start_pos - 1] = '*';
                ans[start_pos] = '*';
            }
        }

        if(abs(start_pos - end_pos) == 1){
            int index = min(start_pos, end_pos);
            ans[index] = '-';

            if(index > 0){
                ans[index - 1] = '*';
            }
        }
    }

    cout << ans;

    return 0;

}
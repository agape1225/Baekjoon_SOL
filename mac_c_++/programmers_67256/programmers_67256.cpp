#include <string>
#include <vector>
#include <utility>
//1, 0 -> 0, 1

using namespace std;

pair<int, int> left_pos;
pair<int, int> right_pos;

int get_dis(int target_row, int target_col, int row, int col){
    int tmp1 = target_row - row;
    int tmp2 = target_col - col;
    
    if(tmp1 < 0)
        tmp1 = -tmp1;
    
    if(tmp2 < 0)
        tmp2 = -tmp2;
    
    return tmp1 + tmp2;
}

pair<int, int> get_pos(int num){
    int cache[4][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {-1,0,-1}
    };
    
    int row;
    int col;
    
    for(row = 0; row < 4; row++){
        for(col = 0; col < 3; col++){
            if(cache[row][col] == num)
                return make_pair(row, col);
        }
    }
}

string get_hands_dir(int num, string hand){
    if(num == 1 || num == 4 || num == 7)
        return "L";
    if(num == 3 || num == 6 || num == 9)
        return "R";
    
    pair<int, int> pos = get_pos(num);
    int left_dis = get_dis(pos.first, pos.second, left_pos.first, left_pos.second);
    int right_dis = get_dis(pos.first, pos.second, right_pos.first, right_pos.second);
    
    if(left_dis < right_dis)
        return "L";
        
    if(right_dis < left_dis)
        return "R";
    
    if(hand == "left")
        return "L";
    return "R";
    
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    left_pos.first = 3;
    left_pos.second = 0;
    
    right_pos.first = 3;
    right_pos.second = 2;
    
    for(int i = 0; i < numbers.size(); i++){
        string dir = get_hands_dir(numbers[i] , hand);
        if(dir == "L"){
            left_pos = get_pos(numbers[i]);
        }else{
            right_pos = get_pos(numbers[i]);
        }
        answer += dir;
    }
    
    return answer;
}
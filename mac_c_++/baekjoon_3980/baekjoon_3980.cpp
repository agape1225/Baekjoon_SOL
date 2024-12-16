#include <iostream>
#include <algorithm>

using namespace std;

bool visited[11] = {0};
int player[11][11];
int answer = -1;

void get_ans(int sum, int player_number){

    if(player_number == 11){
        answer = max(answer, sum);
    }else{
        for(int i = 0; i < 11; i++){
            if(!visited[i] && player[player_number][i] != 0){
                visited[i] = true;
                get_ans(sum + player[player_number][i], player_number + 1);
                visited[i] = false;
            }
        }
    }


}

int main(void){
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        answer = -1;
        
        for(int i = 0; i < 11; i++){
            visited[i] = false;
            for(int j = 0; j < 11; j++){
                cin >> player[i][j];
            }
        }

        get_ans(0, 0);

        cout << answer << '\n';
    }

    return 0;
}
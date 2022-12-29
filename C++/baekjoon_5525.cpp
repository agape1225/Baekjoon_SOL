#include <iostream>
#include <string>

using namespace std;

int main(void){

  int N, M;
  string input;
  string standard = "";
  cin >> N;
  cin >> M;

  cin >> input;

  int ans = 0;
  
  
  for(int i = 0; i < M; i++){
    if(input[i] == 'I'){
      int count = 0;
      while(input[i + 1] == 'O' && input[i + 2] == 'I'){
        count++;
        i += 2;
        if(count == N){
          ans++;
          count--;
        }
      }
    }
  }
  
  cout << ans;
  return 0;
  
}

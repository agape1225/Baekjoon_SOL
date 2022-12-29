#include <iostream>

using namespace std;

int arr[2][6];  //[0] : 방향, [1] : 길이

int main(void){
  int K;

  cin >> K;
  
  for(int i = 0; i < 6; i++){

    cin >> arr[0][i] >> arr[1][i];
    
  }

  int index = 0;

  while(true){

    if((arr[0][index] == arr[0][(index + 2) % 6]) && (arr[0][(index + 1) % 6] == arr[0][(index + 3) % 6])){
      break;
    }
    index++;
  }

  //cout << arr[0][(index + 1) % 6] << endl;

  int ans = (arr[1][index] + arr[1][(index + 2) % 6]) * (arr[1][(index + 1) % 6] + arr[1][(index + 3) % 6]);
  ans -= (arr[1][(index + 1) % 6]) * (arr[1][(index + 2) % 6]);

  cout << ans * K;
  return 0;
  
}

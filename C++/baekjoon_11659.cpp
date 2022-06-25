#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> dp;

int main() {
    
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  int N, M, buff;  
  int num1, num2;
  cin >> N >> M;
  
  for(int i = 0; i < N; i++){
    cin >> buff;
    arr.push_back(buff);
  }

  //make dp
  dp.push_back(arr[0]);
  for(int i = 1; i < N; i++){
    dp.push_back(dp[i - 1] + arr[i]);
  }

  /*for(auto it = dp.begin(); it != dp.end(); it++){
    cout << (*it) << ' ';
  }*/

  
  for(int i = 0; i < M; i++){
    cin >> num1 >> num2;
    //cout << dp[num2 - 1] - dp[num1 - 1] << endl;

    if(num1 == 1){
      cout << dp[num2 - 1] << '\n';
    }else{
      cout << dp[num2 - 1] - dp[num1 - 2] << '\n';
    }
    
  }

  return 0;
  
}

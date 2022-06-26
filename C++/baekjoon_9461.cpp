#include <iostream>
#include <vector>

using namespace std;

vector<long long> dp;

int main(void){

  dp.push_back(1);
  dp.push_back(1);
  dp.push_back(1);
  dp.push_back(2);
  dp.push_back(2);

  for(int i = 5; i < 100; i++){
    dp.push_back(dp[i - 5] + dp[i - 1]);
  }

  int T;
  cin >> T;

  for(int t = 0; t < T; t++){
    int N;
    cin >> N;

    cout << dp[N - 1] << endl;
  }
  
  
  return 0;
  
}

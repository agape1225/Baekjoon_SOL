#include <iostream>
#include <set>

using namespace std;

int main(void){

  set<string> s;
  int N, M;
  int ans = 0;
  string buff;

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> buff;
    s.insert(buff);
  }

  for(int i = 0; i < M; i++){
    cin >> buff;
    if(s.find(buff) != s.end())
      ans++;
  }

  cout << ans;

  return 0;
  
}

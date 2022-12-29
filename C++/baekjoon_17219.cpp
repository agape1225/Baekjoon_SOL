#include <iostream>
#include <map>

using namespace std;

int main(void){
  ios_base :: sync_with_stdio(false); 
  cin.tie(0);
  cout.tie(0);

  map<string, string> passwds;
  int N, M;
  string buff1, buff2;
  
  cin >> N >> M;

  for(int i = 0; i < N; i++){
    cin >> buff1 >> buff2;
    passwds.insert(make_pair(buff1, buff2));
  }

  for(int i = 0; i < M; i++){
    cin >> buff1;
    auto it = passwds.find(buff1);
    cout << (*it).second << '\n';
  }
  
  return 0;
}
